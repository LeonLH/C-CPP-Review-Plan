#pragma once

#include "Student.h"
#include"Manager.h"
#include"SockLH.h"
enum PORT{
	PORT1 = 12345,
	PORT2,
};
class Main
{

	CSockLH m_sock;
	CStudent m_stu;		//�ڽ���m_stu��ʱ���Ѿ��ѳ�Աm_list��ʼ�����ˡ�
	CManager m_man;		//ͬ���ڽ���m_man��ʱ���Ѿ��ѳ�Աm_arr��ʼ�����ˡ����Բ���Ҫ����Load()��Save()��
public:
	Main(void);
	~Main(void);

	void Welcome();
	int Login();
	int Menu();
	
	void Run();
	void Exit();
	bool ConnectServer(void);
	bool DisconnectServer();
};

