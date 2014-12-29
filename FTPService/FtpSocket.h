#ifndef FTPSOCKET_H
#define FTPSOCKET_H

#include "FtpProtocols.h"
#include "../TCPService/TcpSocket.h"
#include <vector>


class FtpSocket : public TcpSocket
{
private:
	std::vector<char> command_buff;
	std::vector<char> data_buff;

public:
	FtpSocket();
	FtpSocket(SOCKET socket, SOCKADDR_IN client_addr);
	FtpSocket(TcpSocket socket);
	~FtpSocket();

	void send_command(FtpCommand& command);
	void send_data(FtpData& data);
	FtpCommand recv_command();
	FtpData recv_data();
};


#endif // FTPSOCKET_H
