#include "FtpProtocols.h"


const int FtpProtocols::PORT_SERVER_COMMAND = 21;
const int FtpProtocols::PORT_SERVER_DATA = 20;
const int FtpProtocols::PORT_CLIENT_DATA = 6000;

const int FtpProtocols::PORT = 0;
const int FtpProtocols::GET = FtpProtocols::PORT + 1;
const int FtpProtocols::PUT = FtpProtocols::GET + 1;
const int FtpProtocols::PWD = FtpProtocols::PUT + 1;
const int FtpProtocols::DIR = FtpProtocols::PWD + 1;
const int FtpProtocols::CD = FtpProtocols::DIR + 1;
const int FtpProtocols::HELP = FtpProtocols::CD + 1;
const int FtpProtocols::QUIT = FtpProtocols::HELP + 1;
