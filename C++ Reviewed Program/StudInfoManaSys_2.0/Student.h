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



typedef int (*funcp)(const DATA *pd1,const DATA *pd2);	//指针类型(int (*)(const DATA *pd1,const DATA *pd2))重命名为funcp
class CStudent
{

	CList<DATA*> m_list;	
public:
	CStudent(void);
	~CStudent(void);
	void RemoveAll();

	void Welcome();
	int Find();
	void FindbyName();
	void FindbySex();
	void FindbySubCate();
	void FindbyNumb();
	void FindbyMath();
	void FindbyGeog();
	void FindbyPhys();
	void Modify();
	void Delete();
	void Input();


	static int byNumb(const DATA *pd1,const DATA *pd2)
	{
		return  pd1->nNumb < pd2->nNumb;
	}
	static int byName(const DATA *pd1,const DATA *pd2)
	{
		return  (strcmp(pd1->sName, pd2->sName)<0);
	}
	static int byMath(const DATA *pd1,const DATA *pd2)
	{
		return  pd1->fMath< pd2->fMath;
	}
	static int byChin(const DATA *pd1,const DATA *pd2)
	{
		return  pd1->fChin< pd2->fChin;
	}
	static int byEngl(const DATA *pd1,const DATA *pd2)
	{
		return  pd1->fEngl< pd2->fEngl;
	}

	static int bySex(const DATA *pd1,const DATA *pd2)
	{
		return  pd1->nSex< pd2->nSex;
	}
	static int byType(const DATA *pd1,const DATA *pd2)
	{
		return  pd1->nType< pd2->nType;
	}

	static int byGeog(const DATA *pd1,const DATA *pd2)
	{
		SArt *psd1 = (SArt*)pd1;
		SArt *psd2 = (SArt*)pd2;
		return  psd1->fGeog< psd2->fGeog;
	}
	static int byHist(const DATA *pd1,const DATA *pd2)
	{
		SArt *psd1 = (SArt*)pd1;
		SArt *psd2 = (SArt*)pd2;
		return  psd1->fHist< psd2->fHist;
	}


	static int byBiol(const DATA *pd1,const DATA *pd2)
	{
		SScn *psd1 = (SScn*)pd1;
		SScn *psd2 = (SScn*)pd2;
		return  psd1->fBiol< psd2->fBiol;
	}
	static int byPhys(const DATA *pd1,const DATA *pd2)
	{
		SScn *psd1 = (SScn*)pd1;
		SScn *psd2 = (SScn*)pd2;
		return  psd1->fPhys< psd2->fPhys;
	}
	static int byChem(const DATA *pd1,const DATA *pd2)
	{
		SScn *psd1 = (SScn*)pd1;
		SScn *psd2 = (SScn*)pd2;
		return  psd1->fChem< psd2->fChem;
	}






	DATA** MallocArray();
	DATA** MallocScnArray();
	DATA** MallocArtArray();
	void FreeArray(DATA** p);
	void CStudent::Print(DATA** p);	//打印排序后的指针数组
	void CStudent::Print(DATA* pData);	//打印单个指针指向的内容

	void Sort(funcp fp);
	int Browse();

	bool IsExist(int n);
	void Print();
	void Load();
	void Save();


};
