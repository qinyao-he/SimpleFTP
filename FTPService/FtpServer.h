#ifndef FTPSERVER_H
#define FTPSERVER_H

#include "FtpAbstract.h"
#include "FtpSocket.h"


class FtpServer : public FtpAbstract
{
private:
	TcpServer tcp_server;

public:
	FtpServer();
	~FtpServer();

	void listen(int port);
};


#endif // FTPSERVER_H
