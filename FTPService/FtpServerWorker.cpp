#include "FtpServerWorker.h"
#include "FtpProtocols.h"
#include <iostream>
#include <fstream>
#include <streambuf>
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
	system("cd > temp");
	std::ifstream file("temp");
	file >> path;
	path += "\\";
	file.close();
	remove("temp");
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
				std::cout << "Client " + socket.get_remote_ip() + " disconnected." << std::endl;
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
				FtpData data;
				data.data_type = FtpProtocols::SUCCESS;
				data.data = std::vector<char>(path.begin(), path.end());
				client_socket.send_data(data);
			}
			else if (command.command_type == FtpProtocols::DIR) {
				std::ofstream outfile("help.bat");
				outfile << "@echo off" << std::endl;
				outfile << "cd " + path << std::endl;
				outfile << "dir" << std::endl;
				outfile.close();
				system("help.bat > temp");
				std::ifstream file("temp");
				std::string result((std::istreambuf_iterator<char>(file)),
									std::istreambuf_iterator<char>());
				file.close();
				remove("help.bat");
				remove("temp");
				FtpData data;
				data.data_type = FtpProtocols::SUCCESS;
				data.data = std::vector<char>(result.begin(), result.end());
				client_socket.send_data(data);
			}
			else if (command.command_type == FtpProtocols::CD) {
				std::string cd_path(command.data.begin(), command.data.end());
				std::ofstream outfile("help.bat");
				outfile << "@echo off" << std::endl;
				outfile << "cd " + path << std::endl;
				outfile << "cd " + cd_path << std::endl;
				outfile << "cd" << std::endl;
				outfile.close();
				system("help.bat > temp");
				std::ifstream file("temp");
				file >> path;
				path += "\\";
				file.close();
				remove("help.bat");
				remove("temp");
				FtpData data;
				data.data_type = FtpProtocols::SUCCESS;
				data.data = std::vector<char>(path.begin(), path.end());
				client_socket.send_data(data);
			}
			else if (command.command_type == FtpProtocols::QUIT) {
				std::cout << "Client " + socket.get_remote_ip() + " disconnected." << std::endl;
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
