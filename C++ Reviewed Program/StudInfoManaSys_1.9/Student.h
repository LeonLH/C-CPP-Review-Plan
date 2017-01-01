#pragma once
#include <iostream>
#include <afxtempl.h>

struct DATA
{
	int nNumb;
	char sName[20];
	int nSex;	//0 For Man,1 For Woman
	int nType;	//0 For 文科，1 For 理科。	
	void Input();
	void Print();
	float fMath;
	float fChin;
	float fEngl;

};
struct SArt:DATA
{
	float fGeog;
	float fHist;
	void Input();
	void Print();

};
struct SScn:DATA
{
	float fBiol;
	float fPhys;
	float fChem;
	void Input();
	void Print();

};



typedef int (*funcp)(const DATA d1,const DATA d2);	//指针类型(int (*)(const DATA d1,const DATA d2))重命名为funcp
class CStudent
{

	CList<DATA*> m_list;	
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
	POSITION* MallocArray();
	void FreeArray(POSITION *p);
	void CStudent::Print(POSITION *p);
	void Sort(funcp fp);
	int Browse();

	bool IsExist(int n);
	void Print();
	void Load();
	void Save();


};

/*
struct DATA
{
	int nNumb;
	char sName[20];
	float fMath;

};
typedef int (*funcp)(const DATA d1,const DATA d2);	//指针类型(int (*)(const DATA d1,const DATA d2))重命名为funcp
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
	POSITION* MallocArray();
	void FreeArray(POSITION *p);
	void CStudent::Print(POSITION *p);
	void Sort(funcp fp);
	int Browse();

	bool IsExist(int n);
	void Print();
	void Load();
	void Save();


};
*/
