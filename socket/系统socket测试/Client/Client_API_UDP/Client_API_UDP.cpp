#include<WinSock2.h>
#include<iostream>
#pragma comment(lib,"ws2_32.lib")

using namespace std;
enum PORT
{
	PORT1 = 10010,	//����
	PORT2 = 10015,	//�Է���
	PORT3 = 10020,	//�����
};


int main()
{
	WSADATA wd;
	WSAStartup(0x0202,&wd);
	SOCKET sock = socket(AF_INET,SOCK_DGRAM,0);
	if(sock == INVALID_SOCKET)
	{
		cout << "�����׽���ʧ�ܣ�"<<WSAGetLastError() <<endl; 
		return -1;
	}

	sockaddr_in sa = {AF_INET,htons(PORT1)};
	sockaddr_in to = {AF_INET,htons(PORT2)};
	sa.sin_addr.S_un.S_addr = inet_addr("192.168.10.101");
	to.sin_addr.S_un.S_addr = inet_addr("192.168.10.101");
	bind(sock,(sockaddr*)&sa,sizeof(sa));

	char ssend[512];
	while (true)
	{
		fflush(stdin);
		cout << "������Ҫ���͵�����" <<endl;
		gets_s(ssend);
		sendto(sock,ssend,strlen(ssend),0,(sockaddr*)&to,sizeof(to));
	}
	

	return 1;
}
//192.168.174.130
//UDP����ʱ����ָ���Է���IP�ͶԷ��Ķ˿ڣ�����Է��ղ�����
