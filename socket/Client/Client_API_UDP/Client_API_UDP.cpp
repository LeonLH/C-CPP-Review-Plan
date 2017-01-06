#include<WinSock2.h>
#include<iostream>
#pragma comment(lib,"ws2_32.lib")

using namespace std;
enum PORT
{
	PORT1 = 10010,	//本机
	PORT2 = 10015,	//对方的
	PORT3 = 10020,	//虚拟机
};


int main()
{
	WSADATA wd;
	WSAStartup(0x0202,&wd);
	SOCKET sock = socket(AF_INET,SOCK_DGRAM,0);
	if(sock == INVALID_SOCKET)
	{
		cout << "建立套接字失败："<<WSAGetLastError() <<endl; 
		return -1;
	}

	sockaddr_in sa = {AF_INET,htons(PORT1)};
	sockaddr_in to = {AF_INET,htons(PORT2)};
	sa.sin_addr.S_un.S_addr = inet_addr("192.168.10.101");
	to.sin_addr.S_un.S_addr = inet_addr("192.168.10.101");
	bind(sock,(sockaddr*)&sa,sizeof(sa));

	char ssend[512];
	while (true)
	{
		fflush(stdin);
		cout << "请输入要发送的内容" <<endl;
		gets_s(ssend);
		sendto(sock,ssend,strlen(ssend),0,(sockaddr*)&to,sizeof(to));
	}
	

	return 1;
}
//192.168.174.130
//UDP发送时必须指定对方的IP和对方的端口，否则对方收不到。
