#ifndef TCPSERVER_H
#define TCPSERVER_H

#include "TcpAbstract.h"
#include "TcpSocket.h"
#include <WinSock2.h>


class TcpServer : public TcpAbstract
{
private:
	SOCKET server_socket;

public:
	TcpServer();
	~TcpServer();

	void listen(int port);
	TcpSocket accept();
};


#endif // TCPSERVER_H
