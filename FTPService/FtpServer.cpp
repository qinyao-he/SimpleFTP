#include "FtpServer.h"


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
	}
}
