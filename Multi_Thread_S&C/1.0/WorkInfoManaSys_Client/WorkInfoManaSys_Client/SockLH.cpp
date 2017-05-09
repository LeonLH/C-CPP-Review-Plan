#include "SockLH.h"
#include<WinSock2.h>
#pragma comment(lib,"ws2_32.lib")

CSockLH::CSockLH(void)
{
	WSADATA wd;
	WSAStartup(0x0202,&wd);
	m_hSocket = INVALID_SOCKET;
}


CSockLH::~CSockLH(void)
{
	Close();
}


BOOL CSockLH::Create(UINT nSocketPort, int nSocketType, LPCTSTR lpszSocketAddress)
{
	m_hSocket = socket(AF_INET,nSocketType,0);
	if(m_hSocket == INVALID_SOCKET)
		return false;
	sockaddr_in sa = {AF_INET,htons(nSocketPort)};
	if(lpszSocketAddress)
		sa.sin_addr.S_un.S_addr = inet_addr(lpszSocketAddress);
	int i = bind(m_hSocket,(sockaddr*)&sa,sizeof(sa));
	return !i;
		
}




BOOL CSockLH::Accept(CSockLH& rConnectedSocket, LPSTR szIP, UINT* nPort)
{
	sockaddr_in sa = {AF_INET};
	int nLen = sizeof(sa);
	rConnectedSocket.m_hSocket = accept(m_hSocket,(sockaddr*)&sa,&nLen);
	m_socka = rConnectedSocket.m_hSocket;
	if(rConnectedSocket.m_hSocket == INVALID_SOCKET)
		return false;
	if(szIP)
		strcpy(szIP,inet_ntoa(sa.sin_addr));
	if(nPort)
		*nPort = htons(sa.sin_port);
	return true;
}

/*	//为什么每次运行a的结果不一样，规律是ture、false、ture、false
	bool a = connect(m_hSocket,(sockaddr*)&sa,sizeof(sa));
	int b = SOCKET_ERROR;
	bool c = SOCKET_ERROR;
	int d =  connect(m_hSocket,(sockaddr*)&sa,sizeof(sa));
	return !a;
*/
BOOL CSockLH::Connect(LPCTSTR lpszHostAddress, UINT nHostPort)
{
	sockaddr_in sa = {AF_INET,ntohs(nHostPort)};
	sa.sin_addr.S_un.S_addr = inet_addr(lpszHostAddress);
	int b = connect(m_hSocket,(sockaddr*)&sa,sizeof(sa));
	return !b;
	/**/
}


int CSockLH::SendTo(const void* lpBuf, int nBufLen, UINT nHostPort, LPCTSTR lpszHostAddress, int nFlags)
{
	sockaddr_in sa = {AF_INET,ntohs(nHostPort)};
	sa.sin_addr.S_un.S_addr = inet_addr(lpszHostAddress);
	return sendto(m_hSocket,(char*)lpBuf,nBufLen,0,(sockaddr*)&sa,sizeof(sa));
}


int CSockLH::ReceiveFrom(void* lpBuf, int nBufLen, char* rSocketAddress, UINT& rSocketPort, int nFlags)
{//
	sockaddr_in sa = {AF_INET};
	int nLen = sizeof(sa);
	int nRet =  recvfrom(m_socka,(char*)lpBuf,nBufLen,0,(sockaddr*)&sa,&nLen);
	if(nRet > 0)
	{
		rSocketPort = htons(sa.sin_port);
		strcpy(rSocketAddress,inet_ntoa(sa.sin_addr));
	}
	return nRet;
}




BOOL CSockLH::GetPeerName(char* rSocketAddress, UINT& rSocketPort)
{
	sockaddr_in sa = {AF_INET};
	int nLen = sizeof(sa);
	if(getpeername(m_socka,(sockaddr*)&sa,&nLen)<0)
		return false;
	strcpy(rSocketAddress,inet_ntoa(sa.sin_addr));	//深拷贝
	/*rSocketAddress = inet_ntoa(sa.sin_addr);//注意此处不能用浅拷贝	*/
	rSocketPort = htons(sa.sin_port);


	return 0;
}


BOOL CSockLH::GetSockName(char* rSocketAddress, UINT& rSocketPort)
{
	sockaddr_in sa = { AF_INET };
	int nLen = sizeof(sa);
	if (getsockname(m_hSocket, (sockaddr*)&sa, &nLen) < 0)
		return FALSE;
	rSocketPort = htons(sa.sin_port);
	strcpy(rSocketAddress, inet_ntoa(sa.sin_addr));
	return TRUE;
}

