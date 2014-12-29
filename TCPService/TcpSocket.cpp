#include "TcpSocket.h"


TcpSocket::TcpSocket(SOCKET socket)
{
	m_socket = socket;
}


TcpSocket::~TcpSocket()
{
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
