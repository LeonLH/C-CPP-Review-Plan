
#include<afxsock.h>
#include<WinSock2.h>

#include <iostream>

#pragma comment(lib,"ws2_32.lib")
using namespace std;

enum PORT{
	PORT1 = 10001,
	PORT2 = 10050,	//本机
	PORT3 = 10003,
};

void main()
{

	AfxSocketInit();
	CAsyncSocket sock;

	int n = sock.Create(10001,SOCK_DGRAM);	//Create功能是创建SOCKET handle

		

	if(!n)
	{
		cout << "接受数据失败：" << GetLastError() <<endl;
		return ;
		
	}	
	while (true)
	{
		char s[256];
		sockaddr_in sa;

		int nLen = sizeof(sa);

		n = sock.ReceiveFrom(s,sizeof(s),(sockaddr*)&sa,&nLen);
		if(n == SOCKET_ERROR)
		{
			cout << "接受数据失败：" << GetLastError() <<endl;

		}
		cout << "对方IP："<<inet_ntoa(sa.sin_addr)<<'\t'<<ntohs(sa.sin_port)<<endl;
		cout << s <<endl;
	}
	sock.Close();



}

//1.CAsyncSocket单步执行到Create()处报错，不知道如何解决！
//		->解决了：前面不加：WSADATA wd;WSAStartup(0x0202,&wd);这两句话，因为在构造函数里面已经定义过了。
//		->上述办法还是不行。
//		->试用AfxSocketInit()初始化，未解决。


