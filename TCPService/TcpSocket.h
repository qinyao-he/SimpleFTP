#ifndef TCPSOCKET_H
#define TCPSOCKET_H

#include <vector>
#include <WinSock2.h>


const int BUFF_LEN = 1000;


class TcpSocket
{
private:
	SOCKET m_socket;
	SOCKADDR_IN m_client_addr;

public:
	TcpSocket(SOCKET socket, SOCKADDR_IN client_addr);
	~TcpSocket();

	void send(std::vector<char>& send_data);
	void recv(std::vector<char>& recv_data);
	void close();
};


#endif // TCPSOCKET_H
