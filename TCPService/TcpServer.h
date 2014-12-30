#ifndef TCPSERVER_H
#define TCPSERVER_H

#include "TcpAbstract.h"


class TcpServer : public TcpAbstract
{
private:
	SOCKET server_socket;

public:
	TcpServer();
	~TcpServer();

	bool listen(int port);
	TcpSocket accept();
};


#endif // TCPSERVER_H
