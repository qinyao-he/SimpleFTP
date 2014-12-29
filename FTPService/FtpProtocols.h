#ifndef FTPPROTOCOLS_H
#define FTPPROTOCOLS_H

#include <vector>


struct FtpCommand_t
{
	int command_type;
	int data_length;
	char data[0];
};


struct FtpData_t
{
	int data_length;
	char data[0];
};

struct FtpCommand
{
	int command_type;
	std::vector<char> data;
};


struct FtpData
{
	std::vector<char> data;
};


class FtpProtocols
{
public:
	static const int PORT_SERVER_COMMAND;
	static const int PORT_SERVER_DATA;
	static const int PORT_CLIENT_DATA;

	static const int PORT;
	static const int GET;
	static const int PUT;
	static const int PWD;
	static const int DIR;
	static const int CD;
	static const int HELP;
	static const int QUIT;

	static FtpCommand to_ftp_command(std::vector<char> buff);
	static FtpData to_ftp_data(std::vector<char> buff);
};


#endif // FTPPROTOCOLS_H
