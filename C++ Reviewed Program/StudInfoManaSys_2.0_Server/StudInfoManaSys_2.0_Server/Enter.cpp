#include"SockLH.h"
#include<iostream>
using namespace std;
enum PORT{
	PORT1 = 12345,
	PORT2,
};
void Function1()
{

}
void Function2()
{

}void Function3()
{

}void Function4()
{

}

void Distribute(char *s)
{
	switch(s[0])
	{
		case 1:
			Function1();
			break;
		case 2:
			Function2();
			break;
		case 3:
			Function3();
			break;
		case 4:
			Function4();
			break;
	}

}

void main()
{
	CSockLH sock;
	sock.Create(PORT1);
	sock.Listen();

	while (true)
	{
		
		CSockLH socka;
		sock.Accept(socka);


		char sIP[20];
		unsigned int nPort;
		socka.GetPeerName(sIP,nPort);
		cout << "IP:" << sIP <<"-" << nPort<<"µÇÂ¼£¡"<<endl;
		const char *str = "Hello Client!";
		socka.Send(str,strlen(str),0);
	
		char s[2048] = {0};	//int s;
		int n = socka.Receive(s,sizeof(s),0);
		if( n == INVALID_SOCKET)
		{
			cout << WSAGetLastError() <<endl;
			break;
		}
		if(!n)
		{
			cout << "IP:" << sIP <<"-" << nPort<<"£ºÒÑÏÂÏß£¡" <<endl;
			break;
		}
		cout << "IP:" << sIP <<"-" << nPort<<"£º"<< s <<endl;
		
		Distribute(s);


		socka.Close();
	

	}	
	

}
