#include<iostream>
#include"HEAD.h"
CList<DATA> g_list;	//最好放在全局区，因为栈内内存有限

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
