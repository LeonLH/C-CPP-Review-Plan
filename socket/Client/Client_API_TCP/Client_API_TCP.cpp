#include<WinSock2.h>
#include<iostream>
#pragma comment(lib,"ws2_32.lib")
using namespace std;

enum PORT
{
	PORT1 = 10010,	//对方的
	PORT2 = 10015,	//本机
	PORT3 = 10020,	//虚拟机

};
int main()
{
	WSADATA wd;
	WSAStartup(0x0202,&wd);
	SOCKET sock = socket(AF_INET,SOCK_STREAM,0);
	if(sock == INVALID_SOCKET)
	{
		cout << "建立套接字失败：" << WSAGetLastError()<< endl;
		return -1;
	}

	sockaddr_in sa = {AF_INET,htons(PORT2)};
	sa.sin_addr.S_un.S_addr = inet_addr("192.168.10.101");
	sockaddr_in to = {AF_INET,htons(PORT1)};
	to.sin_addr.S_un.S_addr = inet_addr("192.168.10.101");

	int n = connect(sock,(sockaddr*)&to,sizeof(to));
	if(n == SOCKET_ERROR)
	{
		cout << "连接失败：" << WSAGetLastError() <<endl;
		return -1;
	}
	int nLen = sizeof(sa);
	while (true)
	{
		char s[256];
		fflush(stdin);
		gets_s(s);
		send(sock,s,sizeof(s),0);
	}





	return 0;
}
