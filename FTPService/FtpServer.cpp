#include "FtpServer.h"
#include "FtpServerWorker.h"

#include <thread>


FtpServer::FtpServer()
{
}


FtpServer::~FtpServer()
{
}


void FtpServer::listen(int port)
{
	tcp_server.listen(port);
	while (true) {
		TcpSocket client_socket = tcp_server.accept();
		std::thread worker(FtpServerWorker(), client_socket);
	}
}
