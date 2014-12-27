#ifndef TCPSERVER_H
#define TCPSERVER_H

#include "TcpAbstract.h"


class TcpServer : public TcpAbstract
{
public:
	TcpServer();
	~TcpServer();

	void listen();
};


#endif // TCPSERVER_H
