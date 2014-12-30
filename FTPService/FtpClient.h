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

	void get(std::string remote_file, std::string local_file);
	void put(std::string local_file, std::string remote_file);
	void pwd();
	void cd(std::string cd_path);
	void dir();
	void quit();
};


#endif // FTPCLIENT_H
