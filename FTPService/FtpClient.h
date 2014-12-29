#ifndef FTPCLIENT_H
#define FTPCLIENT_H

#include "FtpAbstract.h"
#include <string>


class FtpClient : FtpAbstract
{
private:
	TcpClient ftp_command_client;
	TcpServer ftp_data_server;
	TcpSocket command_socket;
	TcpSocket data_socket;

public:
	FtpClient();
	~FtpClient();

	void connect(std::string server_addr);
	void send_command(FtpCommand command);
};


#endif // FTPCLIENT_H
