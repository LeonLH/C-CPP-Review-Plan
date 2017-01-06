#include<afxsock.h>
#include<WinSock2.h>
#include<iostream>
using namespace std;

enum {
	PORT1 = 10010,
	PORT2 = 10011,
	PORT3,
	
};
void main()
{
	AfxSocketInit();
	CSocket sock;
	int n = sock.Create(PORT3);
	if(!n)
	{
		cout << "创建句柄失败：" << GetLastError() << endl;
		return;
	}
	n = sock.Connect("192.168.10.101",PORT1);
	if(!n)
	{
		cout << "连接服务器失败：" << GetLastError() << endl;
		return;
	}
		
	while (true)
	{
		char s[256];
		if(s[0] == '#')	//‘#’退出
			break;
		fflush(stdin);
		gets_s(s);
		n = sock.Send(s,sizeof(s));
		if(SOCKET_ERROR == n)
		{
			cout << "发送数据失败：" << GetLastError() << endl;
			continue;
		}

	}
	sock.Close();

}
