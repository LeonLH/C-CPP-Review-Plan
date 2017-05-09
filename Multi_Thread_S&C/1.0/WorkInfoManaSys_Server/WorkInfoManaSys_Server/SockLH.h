#pragma once
#include<WinSock2.h>
#pragma warning(disable:4996)
class CSockLH
{
protected:
	SOCKET m_hSocket;
public:
	CSockLH(void);
	~CSockLH(void);
	BOOL Create(UINT nSocketPort, int nSocketType = SOCK_STREAM, LPCTSTR lpszSocketAddress = nullptr);
	BOOL Listen(int nConnectionBacklog = 5)
	{
		return !listen(m_hSocket,nConnectionBacklog);
	}

	//注意此处Accept参数的缺省值
	BOOL Accept(CSockLH& rConnectedSocket, LPSTR szIP = nullptr, UINT* nPort = nullptr);
	BOOL Connect(LPCTSTR lpszHostAddress, UINT nHostPort);
	int SendTo(const void* lpBuf, int nBufLen, UINT nHostPort, LPCTSTR lpszHostAddress, int nFlags= 0);
	int ReceiveFrom(void* lpBuf, int nBufLen, char* rSocketAddress, UINT& rSocketPort, int nFlags = 0);
	int Send(const void* lpBuf, int nBufLen, int nFlags = 0)
	{
		return send(m_hSocket,(char*)lpBuf,nBufLen,nFlags);
	}

	int Receive(void* lpBuf, int nBufLen, int nFlags = 0)
	{
		return recv(m_hSocket,(char*)lpBuf,nBufLen,nFlags);
	}

	BOOL GetPeerName(char* rSocketAddress, UINT& rSocketPort);
	BOOL GetSockName(char* rSocketAddress, UINT& rSocketPort);
	void Close(void)
	{
		closesocket(m_hSocket);
		m_hSocket =	INVALID_SOCKET;
	}

private:
	SOCKET m_socka;
};

/*

class CSockLH
{
protected:
	SOCKET m_hSocket;
public:
	CSockLH(void);
	~CSockLH(void);
	BOOL Create(UINT nSocketPort, int nSocketType, LPCTSTR lpszSocketAddress);
	BOOL Listen(int nConnectionBacklog);
	BOOL Accept(CSockLH& rConnectedSocket, LPSTR szIP, UINT* nPort);
	BOOL Connect(LPCTSTR lpszHostAddress, UINT nHostPort);
	int SendTo(const void* lpBuf, int nBufLen, UINT nHostPort, LPCTSTR lpszHostAddress, int nFlags);
	int ReceiveFrom(void* lpBuf, int nBufLen, char* rSocketAddress, UINT& rSocketPort, int nFlags);
	int Send(const void* lpBuf, int nBufLen, int nFlags);
	int Receive(void* lpBuf, int nBufLen, int nFlags);
	BOOL GetPeerName(char* rSocketAddress, UINT& rSocketPort);
	BOOL GetSockName(char* rSocketAddress, UINT& rSocketPort);
	void Close(void);
};
*/