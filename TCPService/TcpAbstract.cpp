#include "TcpAbstract.h"

#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")


int TcpAbstract::num_instance = 0;


TcpAbstract::TcpAbstract()
{
	if (num_instance == 0) {
		WORD VersionRequest;
		WSADATA wsaData;
		VersionRequest = MAKEWORD(2, 2);
		WSAStartup(VersionRequest, &wsaData);
	}
	num_instance++;
}


TcpAbstract::~TcpAbstract()
{
	num_instance--;
	if (num_instance == 0) {
		WSACleanup();
	}
}
