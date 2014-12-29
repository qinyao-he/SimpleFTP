#include "FtpProtocols.h"


const int FtpProtocols::PORT_SERVER_COMMAND = 21;
const int FtpProtocols::PORT_SERVER_DATA = 20;
const int FtpProtocols::PORT_CLIENT_DATA = 6000;

const int FtpProtocols::PORT = 0;
const int FtpProtocols::GET = FtpProtocols::PORT + 1;
const int FtpProtocols::PUT = FtpProtocols::GET + 1;
const int FtpProtocols::PWD = FtpProtocols::PUT + 1;
const int FtpProtocols::DIR = FtpProtocols::PWD + 1;
const int FtpProtocols::CD = FtpProtocols::DIR + 1;
const int FtpProtocols::HELP = FtpProtocols::CD + 1;
const int FtpProtocols::QUIT = FtpProtocols::HELP + 1;


FtpCommand FtpProtocols::to_ftp_command(std::vector<char> buff)
{
	int len = buff.size();
	FtpCommand_t* _command_t = (FtpCommand_t*)malloc(len);
	FtpCommand command;
	command.command_type = _command_t->command_type;
	command.data = std::vector<char>(&(_command_t->data[0]), &(_command_t->data[_command_t->data_length]));
	return command;
}


FtpData FtpProtocols::to_ftp_data(std::vector<char> buff)
{
	int len = buff.size();
	FtpData_t* _data_t = (FtpData_t*)malloc(len);
	FtpData data;
	data.data = std::vector<char>(&(_data_t->data[0]), &(_data_t->data[_data_t->data_length]));
	return data;
}
