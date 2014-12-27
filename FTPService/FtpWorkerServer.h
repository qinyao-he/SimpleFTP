#ifndef FTPWORKERSERVER_H
#define FTPWORKERSERVER_H

#include "FtpWorkerAbstract.h"

class FtpWorkerServer : FtpWorkerAbstract
{
public:
	FtpWorkerServer();
	~FtpWorkerServer();

	void operator () (TcpSocket socket);
};


#endif // FTPWORKERSERVER_H
