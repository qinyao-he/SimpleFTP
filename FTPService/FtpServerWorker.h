#ifndef FTPSERVERWORKER_H
#define FTPSERVERWORKER_H

#include "../TCPService/TcpSocket.h"
#include "../TCPService/TcpClient.h"
#include "FtpSocket.h"


class FtpServerWorker
{
public:
	FtpServerWorker();
	~FtpServerWorker();

	void operator () (FtpSocket socket);
};


#endif // FTPSERVERWORKER_H
