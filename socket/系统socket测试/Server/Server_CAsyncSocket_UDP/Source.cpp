
#include<afxsock.h>
#include<WinSock2.h>

#include <iostream>

#pragma comment(lib,"ws2_32.lib")
using namespace std;

enum PORT{
	PORT1 = 10001,
	PORT2 = 10050,	//����
	PORT3 = 10003,
};

void main()
{

	AfxSocketInit();
	CAsyncSocket sock;

	int n = sock.Create(10001,SOCK_DGRAM);	//Create�����Ǵ���SOCKET handle

		

	if(!n)
	{
		cout << "��������ʧ�ܣ�" << GetLastError() <<endl;
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
			cout << "��������ʧ�ܣ�" << GetLastError() <<endl;

		}
		cout << "�Է�IP��"<<inet_ntoa(sa.sin_addr)<<'\t'<<ntohs(sa.sin_port)<<endl;
		cout << s <<endl;
	}
	sock.Close();



}

//1.CAsyncSocket����ִ�е�Create()��������֪����ν����
//		->����ˣ�ǰ�治�ӣ�WSADATA wd;WSAStartup(0x0202,&wd);�����仰����Ϊ�ڹ��캯�������Ѿ�������ˡ�
//		->�����취���ǲ��С�
//		->����AfxSocketInit()��ʼ����δ�����


