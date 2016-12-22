#include <iostream>
#include <afxtempl.h>




struct DATA
{
	int nNumb;
	char sName[20];
	float fMath;

};

extern CList<DATA> g_list;






void Welcome();
void Load();
int Menu();
void Save();
bool IsExist(int n);


