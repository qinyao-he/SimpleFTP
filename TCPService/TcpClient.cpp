#include "TcpClient.h"


TcpClient::TcpClient()
{
}


TcpClient::~TcpClient()
{
}


TcpSocket TcpClient::connect(std::string server_addr, int port)
{
	SOCKET socket = ::socket(AF_INET, SOCK_STREAM, 0);

	SOCKADDR_IN server_socket_addr;
	server_socket_addr.sin_addr.S_un.S_addr = inet_addr(server_addr.c_str());
	server_socket_addr.sin_family = AF_INET;
	server_socket_addr.sin_port = htons(port);
	::connect(socket, (SOCKADDR*)&server_socket_addr, sizeof(SOCKADDR));

	return TcpSocket(socket, server_socket_addr);
}