#include "Admin.h"
#include<iostream>
#include<process.h>
using namespace std;


CAdmin::CAdmin(void)
{
}


CAdmin::~CAdmin(void)
{
	
}


static void NewThread(void *p)
{
	CSockLH socka = *((CSockLH*)p); 
	char *s = "Hello Client! Your have connected the Server!" ;
	socka.Send(s,strlen(s));	
	while (true)
	{
		int nProt;
		socka.Receive((int*)&nProt,sizeof(int));
		OnReceive(nProt,socka);		//此处应该把协议号nProt和socka都传入OnReceive中
	}
}



void CAdmin::Run(void)
{
	m_Asock.Create(PORT1);
	m_Asock.Listen();

	BOOL b;
	CSockLH socka;

	while (true)
	{
		b = m_Asock.Accept(socka);
		if(!b)				//连接成功
			continue;		
	
	
		_beginthread(NewThread,0,&socka);


	
	}
}




bool CAdmin::Login(CSockLH &socka)
{
	HDATA h;
	socka.Receive(&h,sizeof(h));
	HDATA rh;
	bool b = m_Ahr.IsNamePwMatch(h,rh);
	if(!b)
		return false;
	socka.Send(&b,sizeof(b));
	socka.Send(&rh,sizeof(rh));
	return true;
}




bool CAdmin::OnReceive(int nProt,CSockLH &socka)
{
	switch (nProt)
	{
	case ADMIN_LOGIN:					//登录失败要循环登录,成功就退出
		while (!Login(socka))			//登录信息要放在协议分发阶段里面
			;
		break;
	case WORK_ADD:
		break;
	case WORK_DELETE:
		break;
	case WORk_MODIFY:
		break;
	case WORK_SAVE:
		break;
	case WORK_LOAD:
		break;
	case HR_ADD:
		break;
	case HR_DELETE:
		break;
	case HR_MODIFY:
		break;
	case HR_SAVE:
		break;
	case HR_LOAD:
		break;
	default:
		break;
	}
	return true;
}


bool CAdmin::Connect(void)
{
	

	return 0;

}
