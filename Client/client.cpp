#include <iostream>
#include "../FTPService/FtpClient.h"

int main()
{
	FtpClient client;
	client.connect("127.0.0.1");
	return 0;
}
