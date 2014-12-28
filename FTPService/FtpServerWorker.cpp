#include "FtpServerWorker.h"


FtpServerWorker::FtpServerWorker()
{
}


FtpServerWorker::~FtpServerWorker()
{
}


void FtpServerWorker::operator() (TcpSocket socket)
{
	socket.close();
}
