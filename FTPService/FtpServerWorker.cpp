#include "FtpServerWorker.h"
#include "FtpProtocols.h"
#include <iostream>
#include <fstream>
#include <string>


FtpServerWorker::FtpServerWorker()
{
}


FtpServerWorker::~FtpServerWorker()
{
}


bool FtpServerWorker::read_file(std::string& file_path, std::vector<char>& data)
{
	std::ifstream file(file_path, std::ios::binary);
	if (!file.is_open()) {
		return false;
	}
	file.seekg(0, std::ios::end);
	int length = file.tellg();
	file.seekg(0, std::ios::beg);
	data.clear();
	data.resize(length);
	file.read(&data[0], length);
	file.close();
	return true;
}


bool FtpServerWorker::write_file(std::string& file_path, std::vector<char>& data)
{
	std::ofstream file(file_path, std::ios::binary);
	if (!file.is_open()) {
		return false;
	}
	file.write(&data[0], data.size());
	file.close();
	return true;
}


void FtpServerWorker::operator() (FtpSocket socket)
{
	std::string path = "";
	std::cout << "Client connected from: " + socket.get_remote_ip() << std::endl;
	FtpCommand command = socket.recv_command();
	if (command.command_type == FtpProtocols::PORT) {
		int client_port;
		memcpy((void*)&client_port, (void*)&command.data[0], command.data.size());
		TcpClient client;
		FtpSocket client_socket = client.connect(socket.get_remote_ip(), client_port);
		while (true) {
			try {
				command = socket.recv_command();
			}
			catch (int) {
				std::cout << "Remote connection closed." << std::endl;
				break;
			}
			if (command.command_type == FtpProtocols::GET) {
				std::string file(command.data.begin(), command.data.end());
				std::vector<char> file_data;
				read_file(path + file, file_data);
				FtpData data;
				data.data_type = FtpProtocols::SUCCESS;
				data.data = file_data;
				client_socket.send_data(data);
			}
			else if (command.command_type == FtpProtocols::PUT) {
				std::string file(command.data.begin(), command.data.end());
				std::vector<char> file_data = client_socket.recv_data().data;
				write_file(path + file, file_data);
				FtpData data;
				data.data_type = FtpProtocols::SUCCESS;
				client_socket.send_data(data);
			}
			else if (command.command_type == FtpProtocols::PWD) {

			}
			else if (command.command_type == FtpProtocols::DIR) {

			}
			else if (command.command_type == FtpProtocols::CD) {

			}
			else if (command.command_type == FtpProtocols::QUIT) {
				break;
			}
			else {

			}
		}
		client_socket.close();
		socket.close();
	}
	else {
		std::cout << "Error Command" << std::endl;
		socket.close();
		return;
	}
}
