#include "TcpAbstract.h"

#include <WinSock2.h>


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
