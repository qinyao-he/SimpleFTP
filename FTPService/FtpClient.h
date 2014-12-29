#ifndef FTPCLIENT_H
#define FTPCLIENT_H

#include "FtpAbstract.h"
#include <string>

class FtpClient : FtpAbstract
{
public:
	FtpClient();
	~FtpClient();

	void connect(std::string server_addr);
};


#endif // FTPCLIENT_H
