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
		cout << "�������ʧ�ܣ�" << GetLastError() << endl;
		return;
	}
	n = sock.Connect("192.168.10.101",PORT1);
	if(!n)
	{
		cout << "���ӷ�����ʧ�ܣ�" << GetLastError() << endl;
		return;
	}
		
	while (true)
	{
		char s[256];
		if(s[0] == '#')	//��#���˳�
			break;
		fflush(stdin);
		gets_s(s);
		n = sock.Send(s,sizeof(s));
		if(SOCKET_ERROR == n)
		{
			cout << "��������ʧ�ܣ�" << GetLastError() << endl;
			continue;
		}

	}
	sock.Close();

}
