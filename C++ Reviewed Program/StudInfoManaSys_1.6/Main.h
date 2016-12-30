#pragma once
#include "Student.h"
#include"Manager.h"
class Main
{
	CStudent m_stu;		//在建立m_stu的时候已经把成员m_list初始化过了。
	CManager m_man;		//同理，在建立m_man的时候已经把成员m_arr初始化过了。所以不需要调用Load()和Save()。
public:
	Main(void);
	~Main(void);

	void Welcome();
	int Login();
	int Menu();
	
	void Run();
	void Exit();
};

