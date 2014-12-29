#include "TcpSocket.h"


TcpSocket::TcpSocket()
{
}


TcpSocket::TcpSocket(SOCKET socket, SOCKADDR_IN client_addr)
{
	m_socket = socket;
	m_client_addr = client_addr;
}


TcpSocket::~TcpSocket()
{
}


std::string TcpSocket::get_remote_ip()
{
	return std::string(inet_ntoa(m_client_addr.sin_addr));
}


void TcpSocket::send(std::vector<char>& send_data)
{
	::send(m_socket, &send_data[0], send_data.size(), 0);
}


void TcpSocket::recv(std::vector<char>& recv_data)
{
	recv_data.resize(BUFF_LEN);
	int recv_len = ::recv(m_socket, &recv_data[0], BUFF_LEN, 0);
	recv_data.resize(recv_len);
}


void TcpSocket::close()
{
	closesocket(m_socket);
}
