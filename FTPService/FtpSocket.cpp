#include "FtpSocket.h"


FtpSocket::FtpSocket()
{
}

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
	if (_command_t->data_length > 0)
		memcpy(_command_t->data, &command.data[0], _command_t->data_length);
	std::vector<char> buff((char*)_command_t, _command_t->data + _command_t->data_length);
	send(buff);
}


void FtpSocket::send_data(FtpData& data)
{
	FtpData_t* _data_t = (FtpData_t*)malloc(sizeof(_data_t) + data.data.size());
	_data_t->data_type = data.data_type;
	_data_t->data_length = data.data.size();
	if (_data_t->data_length > 0)
		memcpy(_data_t->data, &data.data[0], _data_t->data_length);
	std::vector<char> buff((char*)_data_t, _data_t->data + _data_t->data_length);
	send(buff);
}


FtpCommand FtpSocket::recv_command()
{
	std::vector<char> buff;
	while (command_buff.size() < 2 * sizeof(int)) {
		recv(buff);
		command_buff.insert(command_buff.end(), buff.begin(), buff.end());
	}
	int len;
	memcpy(&len, &command_buff[sizeof(int)], sizeof(int));
	while (command_buff.size() < 2 * sizeof(int) + len) {
		recv(buff);
		command_buff.insert(command_buff.end(), buff.begin(), buff.end());
	}
	FtpCommand command;
	memcpy(&command.command_type, &command_buff[0], sizeof(int));
	command.data.insert(command.data.end(), command_buff.begin() + 2 * sizeof(int), 
						command_buff.begin() + 2 * sizeof(int) + len);
	command_buff.erase(command_buff.begin(), command_buff.begin() + 2 * sizeof(int) + len);
	return command;
}

 
FtpData FtpSocket::recv_data()
{
	std::vector<char> buff;
	while (data_buff.size() < 2 * sizeof(int)) {
		recv(buff);
		data_buff.insert(data_buff.end(), buff.begin(), buff.end());
	}
	int len;
	memcpy(&len, &data_buff[sizeof(int)], sizeof(int));
	while (data_buff.size() < 2 * sizeof(int) + len) {
		recv(buff);
		data_buff.insert(data_buff.end(), buff.begin(), buff.end());
	}
	FtpData data;
	memcpy(&data.data_type, &data_buff[0], sizeof(int));
	data.data.insert(data.data.end(), data_buff.begin() + 2 * sizeof(int), 
					 data_buff.begin() + 2 * sizeof(int) + len);
	data_buff.erase(data_buff.begin(), data_buff.begin() + 2 * sizeof(int) + len);
	return data;
}
