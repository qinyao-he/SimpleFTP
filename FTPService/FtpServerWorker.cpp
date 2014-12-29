#include "FtpServerWorker.h"
#include "FtpProtocols.h"
#include <iostream>


FtpServerWorker::FtpServerWorker()
{
}


FtpServerWorker::~FtpServerWorker()
{
}


void FtpServerWorker::operator() (TcpSocket socket)
{
	std::cout << "Client connected from: " + socket.get_remote_ip() << std::endl;
	std::vector<char> buff;
	socket.recv(buff);
	FtpCommand command = FtpProtocols::to_ftp_command(buff);
	if (command.command_type == FtpProtocols::PORT) {
		int client_port;
		memcpy((void*)&client_port, (void*)&command.data[0], command.data.size());
		TcpClient client;
		TcpSocket client_socket = client.connect(socket.get_remote_ip(), client_port);
	}
	else {

	}
}
