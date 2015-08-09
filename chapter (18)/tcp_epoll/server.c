/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)
#define MAXEVENTS 2048
void do_service(int sockfd);

int main(int argc, const char *argv[])
{
    int listenfd = socket(PF_INET, SOCK_STREAM, 0);
    if(listenfd == -1)
        ERR_EXIT("socket");

    int on = 1;
    if (setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) < 0)
        ERR_EXIT("setsockopt");

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof addr);
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr("192.168.175.128");
    addr.sin_port = htons(8111);
    if(bind(listenfd, (struct sockaddr*)&addr, sizeof addr) == -1)
        ERR_EXIT("bind");

    if(listen(listenfd, SOMAXCONN) == -1)
        ERR_EXIT("listen");

	//创建epoll事件循环
	int efd = epoll_create(MAXEVENTS);
	//int efd = epoll_create1(0);//推荐使用这种方式
	if(-1 == efd)
	{
		perror("epoll_create error");
		exit(EXIT_FAILURE);
	}

	struct epoll_event evt_listen;
	evt_listen.data.fd = listenfd;
	evt_listen.events = EPOLLIN | EPOLLET;
	int ret = epoll_ctl(efd, EPOLL_CTL_ADD, listenfd, &evt_listen);
	if(-1 == ret)
	{
		perror("epoll_ctl add error");
		exit(EXIT_FAILURE);
	}
	
	struct epoll_event *events = calloc(MAXEVENTS, sizeof(struct epoll_event));
	//std::vector<epoll_event> events;

	while(1)
	{
		int idx;
		int nready = epoll_wait(efd, events, MAXEVENTS, -1);	
		for(idx = 0; idx != nready; ++idx)
		{
			int fd = events[idx].data.fd;
			if(fd == listenfd)
			{//新客户端连接到来
				if(events[idx].events & EPOLLIN)
				{
					int peerfd = accept(fd, NULL, NULL);
					if(-1 == peerfd)
					{
						perror("accept error");
						exit(EXIT_FAILURE);
					}
					struct epoll_event ev;
					ev.data.fd = peerfd;
					ev.events = EPOLLIN;
					ret = epoll_ctl(efd, EPOLL_CTL_ADD, peerfd, &ev);
					if(-1 == ret)
					{
						perror("epoll_ctl_add error");
						exit(EXIT_FAILURE);
					}
				}
				printf("client:  ->server: has connected!\n");
			}
			else
			{//与客户端建立的fd
				if(events[idx].events & EPOLLIN)
				{
					char recvbuf[1024] = {0};
					int nread = read(fd, recvbuf, sizeof(recvbuf));
					if(0 == nread)
					{
						struct epoll_event ev;
						ev.data.fd = fd;
						ret = epoll_ctl(efd, EPOLL_CTL_DEL, fd, &ev);
						if(-1 == ret)
						{
							perror("epoll_ctl_del error");
							exit(EXIT_FAILURE);
						}
						close(fd);
						continue;
					}
					printf("recv msg:%s\n", recvbuf);
					int nwrite = write(fd, recvbuf, strlen(recvbuf));
					if(-1 == nwrite)
					{
						perror("send data error");
						close(fd);
					}
				}
			}
		}//end for
	}

    close(listenfd);

    return 0;
}
