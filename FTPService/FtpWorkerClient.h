#ifndef FTPWORKERCLIENT_H
#define FTPWORKERCLIENT_H

#include "FtpWorkerAbstract.h"


class FtpWorkerClient : FtpWorkerAbstract
{
public:
	FtpWorkerClient();
	~FtpWorkerClient();

	void operator () (TcpSocket socket);
};


#endif // FTPWORKERCLIENT_H
