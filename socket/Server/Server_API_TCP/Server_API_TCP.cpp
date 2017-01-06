#include<WinSock2.h>
#include<iostream>
#pragma comment(lib,"ws2_32.lib")
using namespace std;

enum PORT
{
	PORT1 = 10010,	//本机端口，用于侦听

	PORT2 = 10015,	//对方的
	PORT3 = 10020,	//虚拟机
};

void PrintAddr(sockaddr_in &sa)
{
	cout << "IP:" << inet_ntoa(sa.sin_addr) <<"   "<< "PORT:" << htons(sa.sin_port)
		<<endl;

}
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

	sockaddr_in sa = {AF_INET,htons(PORT1)};		
	sa.sin_addr.S_un.S_addr = inet_addr("192.168.10.101");

	int n = bind(sock,(sockaddr*)&sa,sizeof(sa));
	if(n == SOCKET_ERROR)
	{
		cout << "绑定失败："<<WSAGetLastError() <<endl;
		return -1;
	}

	n = listen(sock,5);		//n = 0,侦听成功,侦听不会阻塞

	
	//侦听到了之后，获取对方的端口信息
	sockaddr_in from = {0};
	int nLen = sizeof(from);

	char s[256] = {0};
	while (true)
	{
		//在此处阻塞，接受对方connect，并且新建一个套接字用于收发数据
		SOCKET socka = accept(sock,NULL,NULL);		
		
		n = getpeername(socka,(sockaddr*)&from,&nLen);
		if(n == SOCKET_ERROR)
		{
			cout << "获取对方地址失败："<<WSAGetLastError() <<endl;
			return -1;
		}
		if(socka == INVALID_SOCKET)
		{
			cout << "接受连接失败：" << WSAGetLastError() << endl;
			return -1;
		}
		else
		{
			cout << "客户端：";
			PrintAddr(from);
		}
		while ((n = recv(socka,s,sizeof(s),0))>0)
		{
			cout << s<< endl;
		}
		

	}
	return 0;
}


//sockaddr_in 包含IP和端口信息等
//如何一直侦听？
//需要用到多线程的技术，一个线程用于循环侦听，每收到一次连接请求就新增一个线程
//1.TCP通信有两个socket,一个用于侦听，另一个用于收发数据，侦听不会阻塞，阻塞发生在接受对方的连接请求
//时(即accept peer's connect)。
//2.注意接受数据时接受字符串的大小
//3.socket 句柄是封装在操作系统内核中，而不是在C++ stdlib中的，因此不同的操作系统需要不同的代码
//4.刚开始的时候建议打印WSAGetLastError()，在这里面可能会有debug的参考信息。