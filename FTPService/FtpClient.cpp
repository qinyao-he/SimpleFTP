#include "FtpClient.h"


FtpClient::FtpClient()
{
}


FtpClient::~FtpClient()
{
}


void FtpClient::connect(std::string server_addr)
{
	int data_port = FtpProtocols::PORT_CLIENT_DATA;
	command_socket = ftp_command_client.connect(server_addr, FtpProtocols::PORT_SERVER_COMMAND);
	ftp_data_server.listen(data_port);

	FtpCommand command;
	command.command_type = FtpProtocols::PORT;
	command.data.resize(sizeof(int));
	memcpy(&command.data[0], &data_port, sizeof(int));
	command_socket.send_command(command);
	data_socket = ftp_data_server.accept();
}
