#include "Admin.h"
#include<iostream>
using namespace std;


CAdmin::CAdmin(void)
{
}


CAdmin::~CAdmin(void)
{
	
}


void CAdmin::Welcome(void)
{
}


void CAdmin::Run(void)
{
	
	while(!Connect())
		;

	while(!Login())
		;

	while(Menu())
		;

	
}


bool CAdmin::Login(void)
{
	int nProt = ADMIN_LOGIN;
	m_Asock.Send((int*)&nProt,sizeof(int));
	HDATA h;
	cout << "请输入用户名和密码：用‘ ’隔开" << endl;
	cin >> h.sName >> h.sPass;
	m_Asock.Send(&h,sizeof(h));
	
	HDATA rh;
	bool b;
	m_Asock.Receive(&b,sizeof(b));	
	m_Asock.Receive(&rh,sizeof(rh));
	m_CurUsr = rh;

	if(b)
	{
		cout << "登录成功！"<<endl;
		m_CurUsr = h;
		system("pause");
	}
	return b;
}


bool CAdmin::Load(void)
{
	return false;
}


bool CAdmin::Save(void)
{
	return false;
}




bool CAdmin::Connect(void)
{
	m_Asock.Create(PORT2);				
	BOOL b = m_Asock.Connect("192.168.10.101",PORT1);
	if(!b)
	{
		cout << "连接失败"<<endl;
		return false;
	}

	char s[50] = {0};
	m_Asock.Receive(s,sizeof(s));
	cout << s <<endl;
	return true;
}


int CAdmin::Menu(void)
{


	system("cls");
	puts("\n\n");
	puts("\t\t**********************************************");
	puts("\t\t**********************************************");
	puts("\t\t**********************************************");
	puts("\t\t**********************************************");
	puts("\t\t*******                                *******");
	puts("\t\t*******         1.浏览学生信息         *******");
	puts("\t\t*******         2.添加学生信息         *******");
	puts("\t\t*******         3.删除学生信息         *******");
	puts("\t\t*******         4.修改学生信息         *******");
	puts("\t\t*******         5.查找学生信息         *******");
	puts("\t\t*******         6.修改用户密码         *******");
//	if(!g_curUser.nPrio)
//		puts("\t\t*******         7.账户管理             *******");
	puts("\t\t*******         0.退出                 *******");
	puts("\t\t*******                                *******");
	puts("\t\t**********************************************");
	puts("\t\t**********************************************");
	puts("\t\t**********************************************");
	puts("\t\t**********************************************");
	int i;
	cin>>i;
	switch(i)
		{
			case 1:
				m_Awor.Print();
//				system("pause");
//				while(m_Awor.Browse())
					;
				break;
			case 2:
//				m_Awor.Input();
				break;
			case 3:
//				m_Awor.Delete();
				break;
			case 4:
//				m_Awor.Modify();
				break;
			case 5:
//				while(m_Awor.Find())
					;
				break;
			case 6:
//				while(!m_Ahr.ChangePassWord())
					;
				break;
			case 7:
//				while(m_Ahr.Menu())
					;
				break;
			case 0:
				break;
	}
	
	return i;

}




