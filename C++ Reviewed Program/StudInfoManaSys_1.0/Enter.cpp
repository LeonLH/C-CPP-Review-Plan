#include<iostream>
#include"HEAD.h"
CList<DATA> g_list;	//��÷���ȫ��������Ϊջ���ڴ�����

void main()
{

	system("color 3f");
	Welcome();
	Load();
	while(Menu())
		;
	Save();
	return;
}
