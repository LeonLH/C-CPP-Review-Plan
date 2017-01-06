#include<afxsock.h>
//#include<WinSock2.h>
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
	int n = sock.Create(PORT3,0);
	if(!n)
	{
		cout << "创建句柄失败：" << GetLastError() << endl;
		return;
	}
	sockaddr_in sa = {AF_INET,htons(PORT3)};
	sa.sin_addr.S_un.S_addr = inet_addr("192.168.10.101");
	sockaddr_in to = {AF_INET,htons(PORT1)};
	to.sin_addr.S_un.S_addr = inet_addr("192.168.10.101");
		
	while (true)
	{
		char s[256];
		if(s[0] == '#')	//‘#’退出
			break;
		fflush(stdin);
		gets_s(s);
		n = sock.SendTo(s,sizeof(s),PORT1,"192.168.10.101");
		if(SOCKET_ERROR == n)
		{
			cout << "发送数据失败：" << GetLastError() << endl;
			continue;
		}

	}
	sock.Close();

}
//未通过测试