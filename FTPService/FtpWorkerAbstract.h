#ifndef FTPWORKERABSTRACT_H
#define FTPWORKERABSTRACT_H

#include "../TCPService/TcpSocket.h"


class FtpWorkerAbstract
{
public:
	FtpWorkerAbstract();
	~FtpWorkerAbstract();

	virtual void operator () (TcpSocket socket);
};


#endif // FTPWORKERABSTRACT_H
