
#include<afxsock.h>
#include <iostream>
using namespace std;


enum PORT{
	PORT1 = 10001,
	PORT2 = 10002,	//本机
	PORT3 = 10003,
};

void main()
{

	CAsyncSocket sock;
	sock.Create(PORT2,SOCK_DGRAM);	//Create功能是创建SOCKET handle

	while (true)
	{
		char s[256];
		fflush(stdin);
		gets_s(s);
		sockaddr_in sa;
		sa.sin_port = htons(PORT1);
		sa.sin_addr.S_un.S_addr = inet_addr("192.168.10.101");
		sock.SendTo(s,sizeof(s),(sockaddr*)&sa,sizeof(sa));

	}

}