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
		cout << "�������ʧ�ܣ�" << GetLastError() << endl;
		return;
	}
	sock.Listen();

	while (true)
	{
		
		CSocket socka;
		n = sock.Accept(socka);
		if(!n)
		{
			cout << "���ܶԷ�����ʧ�ܣ�" << GetLastError() << endl;
			return;
		}
		while (true)
		{
			char s[256];
			n = socka.Receive(s,sizeof(s));
			if(SOCKET_ERROR == n)
			{
				cout << "��������ʧ�ܣ�" << GetLastError() << endl;
				break;
			}
			if(!n)
			{
				cout << "�����������ݣ�����رգ�" << endl;
				break;
			}
			cout << s <<endl;
		}
		socka.Close();

	}
}
