#include "FtpClient.h"
#include <iostream>
#include <fstream>


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
	while (!ftp_data_server.listen(data_port))
		data_port++;

	FtpCommand command;
	command.command_type = FtpProtocols::PORT;
	command.data.resize(sizeof(int));
	memcpy(&command.data[0], &data_port, sizeof(int));
	command_socket.send_command(command);
	data_socket = ftp_data_server.accept();
}


void FtpClient::get(std::string remote_file, std::string local_file)
{
	FtpCommand command;
	command.command_type = FtpProtocols::GET;
	command.data = std::vector<char>(remote_file.begin(), remote_file.end());
	command_socket.send_command(command);
	FtpData data = data_socket.recv_data();
	if (data.data_type == FtpProtocols::SUCCESS) {
		std::ofstream file(local_file, std::ios::binary);
		if (!file.is_open()) {
			std::cout << "Write file failed." << std::endl;
			return;
		}
		file.write(&data.data[0], data.data.size());
		file.close();
	}
	else {
		std::cout << "Get file failed." << std::endl;
	}
}


void FtpClient::put(std::string local_file, std::string remote_file)
{
	FtpCommand command;
	command.command_type = FtpProtocols::PUT;
	command.data = std::vector<char>(remote_file.begin(), remote_file.end());
	command_socket.send_command(command);
	FtpData data;
	std::ifstream file(local_file, std::ios::binary);
	if (!file.is_open()) {
		std::cout << "Read file failed." << std::endl;
		return;
	}
	file.seekg(0, std::ios::end);
	int length = file.tellg();
	file.seekg(0, std::ios::beg);
	data.data.resize(length);
	file.read(&data.data[0], length);
	file.close();
	data_socket.send_data(data);
	data = data_socket.recv_data();
	if (data.data_type == FtpProtocols::FAIL) {
		std::cout << "Put file failed." << std::endl;
	}
}


void FtpClient::pwd()
{
	FtpCommand command;
	command.command_type = FtpProtocols::PWD;
	command_socket.send_command(command);
	FtpData data = data_socket.recv_data();
	if (data.data_type == FtpProtocols::SUCCESS) {
		std::string result(data.data.begin(), data.data.end());
		std::cout << result << std::endl;
	}
	else {
		std::cout << "Error." << std::endl;
	}
}


void FtpClient::dir()
{
	FtpCommand command;
	command.command_type = FtpProtocols::DIR;
	command_socket.send_command(command);
	FtpData data = data_socket.recv_data();
	if (data.data_type == FtpProtocols::SUCCESS) {
		std::string result(data.data.begin(), data.data.end());
		std::cout << result << std::endl;
	}
	else {
		std::cout << "Error." << std::endl;
	}
}


void FtpClient::cd(std::string cd_path)
{
	FtpCommand command;
	command.command_type = FtpProtocols::CD;
	command.data = std::vector<char>(cd_path.begin(), cd_path.end());
	command_socket.send_command(command);
	FtpData data = data_socket.recv_data();
	if (data.data_type == FtpProtocols::SUCCESS) {
		std::string result(data.data.begin(), data.data.end());
		std::cout << result << std::endl;
	}
	else {
		std::cout << "Error." << std::endl;
	}
}


void FtpClient::quit()
{
	FtpCommand command;
	command.command_type = FtpProtocols::QUIT;
	command_socket.send_command(command);
}
