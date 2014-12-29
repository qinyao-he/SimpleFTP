#include "FtpSocket.h"


FtpSocket::FtpSocket(SOCKET socket, SOCKADDR_IN client_addr)
	: TcpSocket(socket, client_addr)
{
}


FtpSocket::FtpSocket(TcpSocket socket)
	: TcpSocket(socket)
{
}


FtpSocket::~FtpSocket()
{
}


void FtpSocket::send_command(FtpCommand& command)
{
	FtpCommand_t* _command_t = (FtpCommand_t*)malloc(sizeof(_command_t) + command.data.size());
	_command_t->command_type = command.command_type;
	_command_t->data_length = command.data.size();
	memcpy(_command_t->data, &command.data[0], _command_t->data_length);
	std::vector<char> buff((char*)_command_t, _command_t->data + _command_t->data_length);
	send(buff);
}


void FtpSocket::send_data(FtpData& data)
{
	FtpData_t* _data_t = (FtpData_t*)malloc(sizeof(_data_t) + data.data.size());
	_data_t->data_length = data.data.size();
	memcpy(_data_t->data, &data.data[0], _data_t->data_length);
	std::vector<char> buff((char*)_data_t, _data_t->data + _data_t->data_length);
	send(buff);
}


FtpCommand FtpSocket::recv_command()
{
	return FtpCommand();
}


FtpData FtpSocket::recv_data()
{
	return FtpData();
}
