#include<WinSock2.h>
#include<iostream>
#pragma comment(lib,"ws2_32.lib");

using namespace std;
enum{
	PORT = 12345,
	
};
void main()
{
	WSADATA wd;
	WSAStartup(0x0202,&wd);
	SOCKET sock = socket(AF_INET,SOCK_STREAM,0);	//Ç°Ì¨½Ó´ý
	if(sock == INVALID_SOCKET)
	{
		cout << WSAGetLastError()<<endl;
		return;
	}

	sockaddr_in sa = {AF_INET};

	int n = bind(sock,(sockaddr*)&sa,sizeof(sa));
	if(n == SOCKET_ERROR)
	{
		cout << WSAGetLastError() <<endl;
		return;
	}
	sockaddr_in to = {AF_INET,htons(PORT)};
	to.sin_addr.S_un.S_addr = inet_addr("192.168.10.101");
	
	connect(sock,(sockaddr*)&to,sizeof(to));
	if(n == SOCKET_ERROR)
	{
		cout << WSAGetLastError() <<endl;
		return;
	}
	char s[2048] = {0};
	n = recv(sock,s,sizeof(s),0);
	cout << s << endl;

	while (true)
	{
		gets_s(s);	//cin >> s;
		int n = send(sock,s,strlen(s),0);
		if(n == SOCKET_ERROR)
		{
			cout << WSAGetLastError() <<endl;
			break ;
		}
	}
	

}