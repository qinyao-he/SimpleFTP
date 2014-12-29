#include <iostream>
#include "../FTPService/FtpServer.h"

int main()
{
	FtpServer server;
	server.listen(FtpProtocols::PORT_SERVER_COMMAND);
	return 0;
}
