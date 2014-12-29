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
	send_command(command);
}


void FtpClient::send_command(FtpCommand command)
{
	FtpCommand_t* _command_t = (FtpCommand_t*)malloc(command.data.size() + sizeof(command.command_type));
	_command_t->command_type = command.command_type;
	_command_t->data_length = command.data.size();
	memcpy(_command_t->data, &command.data[0], command.data.size());
	std::vector<char> buff((char*)_command_t, _command_t->data + _command_t->data_length);
	command_socket.send(buff);
}
