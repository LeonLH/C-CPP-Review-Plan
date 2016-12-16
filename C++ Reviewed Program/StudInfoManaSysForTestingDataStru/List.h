#pragma once
struct DATA
{
	int nNumb;
	float fMath;
	char sName[20];
};
struct SNode
{
	DATA SStud;
	SNode *pNext;
	SNode *pPrev;
};

class List
{
	SNode *g_pHead;

public:
	List(void);
	~List(void);
//	void Add(int nNumb);
//	void Delete(int nNumb);
//	void Modify(int nNumb);
//	int nCount(void);
};

