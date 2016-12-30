#pragma once
#include <iostream>
#include <afxtempl.h>

struct DATA
{
	int nNumb;
	char sName[20];
	float fMath;

};

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

	void SortbyName();
	void SortbyNumb();
	void SortbyMath();
	int Browse();

	bool IsExist(int n);
	void Print();
	void Load();
	void Save();
};

