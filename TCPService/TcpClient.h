#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include "TcpAbstract.h"


class TcpClient
{
public:
	TcpClient();
	~TcpClient();

	TcpSocket connect(std::string server_addr, int port);
};


#endif // TCPCLIENT_H
