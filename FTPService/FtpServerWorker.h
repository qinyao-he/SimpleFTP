#ifndef FTPSERVERWORKER_H
#define FTPSERVERWORKER_H

#include "../TCPService/TcpSocket.h"


class FtpServerWorker
{
public:
	FtpServerWorker();
	~FtpServerWorker();

	void operator () (TcpSocket socket);
};


#endif // FTPSERVERWORKER_H
