#ifndef TCPABSTRACT_H
#define TCPABSTRACT_H

#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include "TcpSocket.h"
#include <string>
#include <WinSock2.h>
#include <WS2tcpip.h>


class TcpAbstract
{
private:
	static int num_instance;

public:
	TcpAbstract();
	~TcpAbstract();
};


#endif // TCPABSTRACT_H
