#ifndef FTPCLIENT_H
#define FTPCLIENT_H

#include "FtpAbstract.h"
#include "FtpSocket.h"
#include <string>


class FtpClient : public FtpAbstract
{
private:
	TcpClient ftp_command_client;
	TcpServer ftp_data_server;
	FtpSocket command_socket;
	FtpSocket data_socket;

public:
	FtpClient();
	~FtpClient();

	void connect(std::string server_addr);
};


#endif // FTPCLIENT_H
