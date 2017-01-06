#include<afxsock.h>
//#include<WinSock2.h>
#include<iostream>
using namespace std;

enum {
	PORT1 = 10010,
	PORT2 = 10011,
	
};
void main()
{
	AfxSocketInit();
	CSocket sock;
	int n = sock.Create(PORT1,0);
	if(!n)
	{
		cout << "创建句柄失败：" << GetLastError() << endl;
		return;
	}
	sockaddr_in sa = {AF_INET,htons(PORT1)};
	sa.sin_addr.S_un.S_addr = inet_addr("192.168.10.101");
	sockaddr_in from = {AF_INET};
	int nLen = sizeof(from);
	while (true)
	{
		char s[256];
		n = sock.ReceiveFrom(s,sizeof(s),(sockaddr*)&sa,&nLen);
		if(SOCKET_ERROR == n)
		{
			cout << "接收数据失败：" << GetLastError() << endl;
			continue;
		}
		if(!n)
		{
			cout << "结束接收数据，句柄关闭！" << endl;
			continue;
		}
		cout << "IP:"<< inet_ntoa(from.sin_addr) << "\tPORT:"<< ntohs(from.sin_port)<<endl;
		cout << s <<endl;
	}
	sock.Close();

}

//未通过测试
