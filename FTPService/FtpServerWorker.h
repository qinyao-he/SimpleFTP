#ifndef FTPSERVERWORKER_H
#define FTPSERVERWORKER_H

#include "../TCPService/TcpSocket.h"
#include "../TCPService/TcpClient.h"
#include "FtpSocket.h"


class FtpServerWorker
{
private:
	bool read_file(std::string& file_path, std::vector<char>& data);
	bool write_file(std::string& file_path, std::vector<char>& data);

public:
	FtpServerWorker();
	~FtpServerWorker();

	void operator () (FtpSocket socket);
};


#endif // FTPSERVERWORKER_H
