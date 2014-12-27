#include "TcpServer.h"


TcpServer::TcpServer()
{
}


TcpServer::~TcpServer()
{
}


void TcpServer::listen(int port)
{
	server_socket = socket(AF_INET, SOCK_STREAM, 0);

	SOCKADDR_IN addr;
	addr.sin_family = AF_INET;
	addr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	addr.sin_port = htons(port);

	bind(server_socket, (SOCKADDR*)&addr, sizeof(SOCKADDR));
	::listen(server_socket, 10);
}


TcpSocket TcpServer::accept()
{
	SOCKADDR_IN _client_addr;
	int len = sizeof(SOCKADDR);
	SOCKET socket = ::accept(server_socket, (SOCKADDR*)&_client_addr, &len);
	return TcpSocket(socket, _client_addr);
}
