#include<WinSock2.h>
#include<iostream>
#pragma comment(lib,"ws2_32.lib")
using namespace std;

enum PORT
{
	PORT1 = 10010,	//�����˿ڣ���������

	PORT2 = 10015,	//�Է���
	PORT3 = 10020,	//�����
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
		cout << "�����׽���ʧ�ܣ�" << WSAGetLastError()<< endl;
		return -1;
	}

	sockaddr_in sa = {AF_INET,htons(PORT1)};		
	sa.sin_addr.S_un.S_addr = inet_addr("192.168.10.101");

	int n = bind(sock,(sockaddr*)&sa,sizeof(sa));
	if(n == SOCKET_ERROR)
	{
		cout << "��ʧ�ܣ�"<<WSAGetLastError() <<endl;
		return -1;
	}

	n = listen(sock,5);		//n = 0,�����ɹ�,������������

	
	//��������֮�󣬻�ȡ�Է��Ķ˿���Ϣ
	sockaddr_in from = {0};
	int nLen = sizeof(from);

	char s[256] = {0};
	while (true)
	{
		//�ڴ˴����������ܶԷ�connect�������½�һ���׽��������շ�����
		SOCKET socka = accept(sock,NULL,NULL);		
		
		n = getpeername(socka,(sockaddr*)&from,&nLen);
		if(n == SOCKET_ERROR)
		{
			cout << "��ȡ�Է���ַʧ�ܣ�"<<WSAGetLastError() <<endl;
			return -1;
		}
		if(socka == INVALID_SOCKET)
		{
			cout << "��������ʧ�ܣ�" << WSAGetLastError() << endl;
			return -1;
		}
		else
		{
			cout << "�ͻ��ˣ�";
			PrintAddr(from);
		}
		while ((n = recv(socka,s,sizeof(s),0))>0)
		{
			cout << s<< endl;
		}
		

	}
	return 0;
}


//sockaddr_in ����IP�Ͷ˿���Ϣ��
//���һֱ������
//��Ҫ�õ����̵߳ļ�����һ���߳�����ѭ��������ÿ�յ�һ���������������һ���߳�
//1.TCPͨ��������socket,һ��������������һ�������շ����ݣ������������������������ڽ��ܶԷ�����������
//ʱ(��accept peer's connect)��
//2.ע���������ʱ�����ַ����Ĵ�С
//3.socket ����Ƿ�װ�ڲ���ϵͳ�ں��У���������C++ stdlib�еģ���˲�ͬ�Ĳ���ϵͳ��Ҫ��ͬ�Ĵ���
//4.�տ�ʼ��ʱ�����ӡWSAGetLastError()������������ܻ���debug�Ĳο���Ϣ��