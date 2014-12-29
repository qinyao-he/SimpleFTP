#ifndef FTPPROTOCOLS_H
#define FTPPROTOCOLS_H


struct FtpCommand
{
	int command_type;
	int data_length;
	char data[0];
};


struct FtpData
{
	int data_length;
	char data[0];
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
};


#endif // FTPPROTOCOLS_H
