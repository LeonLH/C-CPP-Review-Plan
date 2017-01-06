
#include<winsock2.h>
#include<iostream>


#pragma comment(lib,"ws2_32.lib")

using namespace std;
enum  
{
	PORT1 = 10010,	//�Է�
	PORT2 = 10015,	//����
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

	sockaddr_in sa = {AF_INET,htons(PORT2)};
	sockaddr_in from = {AF_INET};
	sa.sin_addr.S_un.S_addr = inet_addr("192.168.10.101");
	

	int n = bind(sock,(sockaddr*)&sa,sizeof(sa));
	if(SOCKET_ERROR == n)
	{
		cout << "���׽���ʱ��" <<WSAGetLastError() <<endl;
		return -1;
	}
	int nLen = sizeof(from);
	while (true)
	{
		char srecv[512]={0};

		//n = recv(sock,srecv,strlen(srecv),0);
		//�ڴ˴�������
		n = recvfrom(sock,srecv,sizeof(srecv),0,(sockaddr*)&from,&nLen);
		if(n == SOCKET_ERROR)
		{
			cout << "��������ʱ����" << WSAGetLastError() <<endl;
			return -1;
		}
		cout << srecv << endl;
		//char sIP[32];
		//int nPort;
		cout << "IP:" << inet_ntoa(from.sin_addr)<<"\tPORT:"<<ntohs(from.sin_port)<<endl;
	}
	



	return 0;
}
//1.ע��տ�ʼ��������ʱ���ӡ������ϢWSAGetLastError()���б�Ҫ��