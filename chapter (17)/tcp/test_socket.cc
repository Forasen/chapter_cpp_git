/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include "InetAddress.h"
#include "Socket.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{

	wd::InetAddress addr("192.168.175.128", 9999);

	wd::Socket sock;
    sock.setReusePort(true);
    sock.setReuseAddr(true);

    sock.bindAddress(addr);
    sock.listen();

    int peerfd = sock.accept();

    while(1)
    {
        char recvbuf[1024] = {0};
        ::read(peerfd, recvbuf, sizeof recvbuf);
        printf("receive msg : %s", recvbuf);
        ::write(peerfd, recvbuf, strlen(recvbuf));
    }
    return 0;
}
