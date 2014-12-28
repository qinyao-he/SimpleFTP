#include "TcpAbstract.h"

#include <WinSock2.h>
#pragma comment(lib,"ws2_32.lib")


TcpAbstract::TcpAbstract()
{
	WORD VersionRequest;
	WSADATA wsaData;
	VersionRequest = MAKEWORD(2, 2);
	WSAStartup(VersionRequest, &wsaData);
}


TcpAbstract::~TcpAbstract()
{
	WSACleanup();
}
