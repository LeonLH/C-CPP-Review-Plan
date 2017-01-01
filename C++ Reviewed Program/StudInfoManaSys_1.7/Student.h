#pragma once
#include <iostream>
#include <afxtempl.h>

struct DATA
{
	int nNumb;
	char sName[20];
	float fMath;

};
//typedef int (*funcp)(const POSITION p1,const POSITION p2);
//int (*funcp)(const DATA d1,const DATA d2);

typedef int (*funcp)(const DATA d1,const DATA d2);	//指针类型重命名为funcp
class CStudent
{

	CList<DATA> m_list;	
public:
	CStudent(void);
	~CStudent(void);

	void Welcome();
	int Find();
	void FindbyMath();
	void FindbyName();
	void FindbyNumb();
	void Modify();
	void Delete();
	void Input();


	static int byNumb(const DATA d1,const DATA d2)
	{
		return  d1.nNumb < d2.nNumb;
	}
	static int byName(const DATA d1,const DATA d2)
	{
		return  (strcmp(d1.sName, d2.sName)<0);
	}
	static int byMath(const DATA d1,const DATA d2)
	{
		return  d1.fMath< d2.fMath;
	}
	void Sort(funcp fp);
	int Browse();

	bool IsExist(int n);
	void Print();
	void Load();
	void Save();


};

