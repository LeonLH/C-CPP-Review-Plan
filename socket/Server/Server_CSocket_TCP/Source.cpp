#include<afxsock.h>
#include<WinSock2.h>
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
	int n = sock.Create(PORT1);
	if(!n)
	{
		cout << "创建句柄失败：" << GetLastError() << endl;
		return;
	}
	sock.Listen();

	while (true)
	{
		
		CSocket socka;
		n = sock.Accept(socka);
		if(!n)
		{
			cout << "接受对方连接失败：" << GetLastError() << endl;
			return;
		}
		while (true)
		{
			char s[256];
			n = socka.Receive(s,sizeof(s));
			if(SOCKET_ERROR == n)
			{
				cout << "接收数据失败：" << GetLastError() << endl;
				break;
			}
			if(!n)
			{
				cout << "结束接收数据，句柄关闭！" << endl;
				break;
			}
			cout << s <<endl;
		}
		socka.Close();

	}
}
