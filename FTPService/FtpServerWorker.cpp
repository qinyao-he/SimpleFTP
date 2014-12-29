#include "FtpServerWorker.h"
#include "FtpProtocols.h"
#include <iostream>
#include <string>


FtpServerWorker::FtpServerWorker()
{
}


FtpServerWorker::~FtpServerWorker()
{
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
		TcpSocket client_socket = client.connect(socket.get_remote_ip(), client_port);
		while (true) {
			command = socket.recv_command();
			if (command.command_type == FtpProtocols::GET) {
				
			}
			else if (command.command_type == FtpProtocols::PUT) {

			}
			else if (command.command_type == FtpProtocols::PWD) {

			}
			else if (command.command_type == FtpProtocols::DIR) {

			}
			else if (command.command_type == FtpProtocols::CD) {

			}
			else if (command.command_type == FtpProtocols::QUIT) {

			}
			else {

			}
		}
	}
	else {
		std::cout << "Error Command" << std::endl;
		socket.close();
		return;
	}
}
