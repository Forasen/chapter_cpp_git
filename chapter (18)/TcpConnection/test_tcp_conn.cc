#include "Socket.h"
#include "TcpConnection.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>

int main(int argc, char const *argv[])
{
    int fd = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(fd == -1)
    {
        perror("create socket error");
        exit(EXIT_FAILURE);
    }

	wd::InetAddress addr("192.168.175.130", 9999);

	wd::Socket sock(fd);

    sock.setTcpNoDelay(false);
    sock.setReusePort(true);
    sock.setReuseAddr(true);
    sock.setKeepAlive(false);

    sock.bindAddress(addr);
    sock.listen();

    int peerfd = sock.accept();

	wd::TcpConnectionPtr conn(new wd::TcpConnection(peerfd));

	//TcpConnection conn(peerfd); 

    while(1)
    {
        std::string msg(conn->receive());
		std::cout << msg << std::endl;
        conn->send(msg);
    }

    conn->shutdown();
    close(fd);

    return 0;
}
