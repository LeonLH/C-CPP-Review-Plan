#include "Main.h"
#include"Student.h"
#include"Manager.h"

using namespace std;
extern TDATA g_curUser;

Main::Main(void)
{
}


Main::~Main(void)
{
}
void Main::Welcome()
{
	puts("\n\n");
	puts("\t\t*************************************************");
	puts("\t\t*************************************************");
	puts("\t\t*************************************************");
	puts("\t\t*************************************************");
	puts("\t\t********                                *********");
	puts("\t\t********    ��ӭ����ѧ����Ϣ����ϵͳ    *********");
	puts("\t\t********                                *********");
	puts("\t\t*************************************************");
	puts("\t\t*************************************************");
	puts("\t\t*************************************************");
	puts("\t\t************************************  byLeonLH  *");
	puts("\t\t*************************************************");
	system("pause");

}


int Main::Menu()
{
	system("cls");
	puts("\n\n");
	puts("\t\t**********************************************");
	puts("\t\t**********************************************");
	puts("\t\t**********************************************");
	puts("\t\t**********************************************");
	puts("\t\t*******                                *******");
	puts("\t\t*******         1.���ѧ����Ϣ         *******");
	puts("\t\t*******         2.���ѧ����Ϣ         *******");
	puts("\t\t*******         3.ɾ��ѧ����Ϣ         *******");
	puts("\t\t*******         4.�޸�ѧ����Ϣ         *******");
	puts("\t\t*******         5.����ѧ����Ϣ         *******");
	puts("\t\t*******         6.�޸��û�����         *******");
	if(!g_curUser.nPrio)
		puts("\t\t*******         7.�˻�����             *******");
	puts("\t\t*******         0.�˳�                 *******");
	puts("\t\t*******                                *******");
	puts("\t\t**********************************************");
	puts("\t\t**********************************************");
	puts("\t\t**********************************************");
	puts("\t\t**********************************************");
	int i;
	scanf_s("%d",&i);
	switch(i)
		{
			case 1:
//				m_stu.Print();
//				system("pause");
				while(m_stu.Browse())
					;
				break;
			case 2:
				m_stu.Input();
				break;
			case 3:
				m_stu.Delete();
				break;
			case 4:
				m_stu.Modify();
				break;
			case 5:
				while(m_stu.Find())
					;
				break;
			case 6:
				while(!m_man.ChangePassWord())
					;
				break;
			case 7:
				while(m_man.Menu())
					;
				break;
			case 0:
				break;
	}
	
	return i;

}

int Main::Login()
{
	return m_man.Login();
}

void Main::Exit()
{

}
void Main::Run()
{
	//�˴����ӷ�������
	ConnectServer();
	while(!Login())
		;
	while(Menu())
		;
	DisconnectServer();
//	Logout();
	Exit();


/**/
}


bool Main::ConnectServer(void)
{

	m_sock.Create(PORT2);
	BOOL b = m_sock.Connect("192.168.10.101",PORT1);
	if(!b)
	{
		cout << "����ʧ�ܣ�"<< WSAGetLastError() <<endl;
		return false;
	}
	char str[20] = {0};		//��ӡ���ȳ������⡣
	m_sock.Receive(str,sizeof(str),0);
	cout << str <<endl;
//	return true;
	return true;



}
bool Main::DisconnectServer()
{
	m_man.Save();
	m_stu.Save();
	m_sock.Close();
	return true;
}
