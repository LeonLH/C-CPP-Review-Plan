#include<WinSock2.h>
#include<iostream>
#include<process.h>

#pragma comment(lib,"ws2_32.lib")

using namespace std;
enum{
	PORT = 12345,
	
};

void NewThread(void* p)
{

	SOCKET *pi = (SOCKET*)p;
	SOCKET socka = *pi;
	sockaddr_in from = {AF_INET};
	int nLen = sizeof(from);
	getpeername(socka,(sockaddr*)&from,&nLen);	
	cout <<"IP:"<<inet_ntoa(from.sin_addr)<<"-"<<"PORT:"<<htons(from.sin_port)<<"\t����!"<<endl;
		
	char *s = "Hello Client!�������Ϸ�������";

	int n = send(socka,s,strlen(s),0);
	if(n == SOCKET_ERROR)
	{
		cout << WSAGetLastError() <<endl;
		
	}
	while (true)
	{
		char str[2048] = {0};
		n = recv(socka,str,sizeof(str),0);
		if(n == SOCKET_ERROR)
			break ;
		cout <<inet_ntoa(from.sin_addr)<<"-"<<htons(from.sin_port)<<"��" <<str << endl;
	}
	closesocket(socka);
	cout <<"IP:"<<inet_ntoa(from.sin_addr)<<"-"<<"PORT:"<<htons(from.sin_port)<<"\t����!"<<endl;
}

void main()
{
	WSADATA wd;
	WSAStartup(0x0202,&wd);
	SOCKET sock = socket(AF_INET,SOCK_STREAM,0);	//ǰ̨�Ӵ�
	if(sock == INVALID_SOCKET)
	{
		cout << WSAGetLastError()<<endl;
		return;
	}

	sockaddr_in sa = {AF_INET,ntohs(PORT)};
	int n = bind(sock,(sockaddr*)&sa,sizeof(sa));
	if(n == SOCKET_ERROR)
	{
		cout << WSAGetLastError() <<endl;
		return;
	}
	listen(sock,5);


	while (true)
	{
		SOCKET socka = accept(sock,NULL,NULL);		//�ͻ�����
		
		_beginthread(NewThread,0,&socka);
	}
}


