#pragma once
//#include "MyList.h"

struct DATA
{
	int i;

	bool operator == (DATA &data) const
	{
		return (i == data.i);
	}
	bool operator != (DATA &data) const
	{
		return (i != data.i);
	}

};

struct SNode
{//结构体成员的变量的初始化是在实例化（new）之后马上对其内部所有的成员变量赋值，结构体的定义
	DATA data;
	SNode *pNext;
	SNode *pPrev;
};

typedef SNode* POSITION;
class CMyList
{
	SNode* m_pHead;
	SNode* m_pTail;
	int m_nCount;
public:

	CMyList(void);
	~CMyList(void);
	bool IsEmpty(void);
	void AddHead(DATA data);
	void AddTail(DATA data);
	POSITION CMyList::InsertAfter(POSITION pos,DATA data);
	POSITION CMyList::InsertBefore(POSITION pos,DATA data);

	void RemoveAt(POSITION pos);
	void RemoveHead(void);
	void RemoveTail(void);
	void RemoveAll(void);
	void SetAt(POSITION pos, DATA data);

	POSITION Find(DATA data, POSITION StartAfter);
	int& FindIndex(DATA data, POSITION StratAfter);
	DATA& GetAt(POSITION pos);
	DATA& GetNext(POSITION pos);	//可以用于遍历，返回的是pos处的DATA，并且把pos往下移一位

	POSITION GetHeadPosition();


/*	const DATA& CMyList::GetAt(POSITION pos) const;
//	DATA& GetHead(void);
//	const DATA& CMyList::GetHead(void) const;
*/
};
CMyList::CMyList(void)
{
	m_pHead = nullptr;
	m_pTail = nullptr;
	m_nCount = 0;
}

CMyList::~CMyList(void)
{
	POSITION p = m_pHead;
	POSITION q = nullptr;
	while(p!=m_pTail)
	{
		q = p;
		delete q;
		p = p->pNext;
	}
	delete p;


	
}
//增
void CMyList::AddHead(DATA data)
{

	SNode *pNew = new SNode;
	pNew->pNext = m_pHead;
	pNew->pPrev = nullptr;
	pNew->data = data;
	m_pHead = pNew;
	m_nCount += 1;

	if(!m_pTail)	//链表为空的情况
		m_pTail = pNew;
}

bool CMyList::IsEmpty(void)
{
	if(!m_pHead )
		return true;
	return false;
}
void CMyList::AddTail(DATA data)
{

	SNode *pNew = new SNode;
	pNew->pNext = nullptr;
	pNew->pPrev = m_pTail;
	pNew->data  = data;

	m_nCount += 1;
	m_pTail = pNew;
	if(!m_pHead)	//列表为空的情况
		m_pHead = pNew;
	
}

POSITION CMyList::InsertAfter(POSITION pos,DATA data)
{
	POSITION p = m_pHead;
	while(p != pos)
		p = p->pNext;
	p = p->pNext;

	SNode *pNew = new SNode;
	pNew->pPrev = pos;
	pNew->pNext = p;
	pNew->data = data;

	pos->pNext = pNew;

	if(p)
		p->pPrev = pNew;
	else
		m_pTail = pNew;
	m_nCount += 1;
	return pNew;



}

POSITION CMyList::InsertBefore(POSITION pos,DATA data)
{
	POSITION p = m_pHead;

	while(p != pos)
		p = p->pNext;
	p = p->pPrev;

	SNode *pNew = new SNode;
	pNew->pPrev = p;
	pNew->pNext = pos;
	pNew->data = data;
	
	pos->pPrev = pNew;
	
	if(p)
		p->pNext = pNew;
	else
		m_pHead = pNew;
	m_nCount += 1;
	return pNew;
}

//删
void CMyList::RemoveAt(POSITION pos)
{
	POSITION p = m_pHead;
	while(p!=pos)
		p = p->pNext;
	p->pPrev->pNext = p->pNext;
	p->pNext->pPrev = p->pPrev;
	m_nCount -= 1;
	delete p;
}


void CMyList::RemoveHead(void)
{
	POSITION p = m_pHead;
	m_pHead = p->pNext;
	m_nCount -= 1;
	delete p;
}

void CMyList::RemoveTail(void)
{
	POSITION p = m_pTail;
	m_pTail = p->pPrev;
	m_nCount -= 1;
	delete p;
}

void CMyList::RemoveAll(void)
{
	POSITION p = m_pHead;
	POSITION q = nullptr;
	while(p)
	{
		q = p;
		delete q;
		p = p->pNext;
	}
	m_nCount = 0;
	return;
}

//改
void CMyList::SetAt(POSITION pos, DATA data)
{
	POSITION p = m_pHead;
	while(p != pos)
		p = p->pNext;
	p->data = data;
}
//查
POSITION CMyList::Find(DATA data, POSITION StartAfter = nullptr)
{
	POSITION p;
	if(!StartAfter)
		p = m_pHead;
	else
		p = StartAfter;
	while((p->data != data)&& p )
		p = p->pNext;
	if(!p)
		return nullptr;
	else 
		return p;
}
//位置

DATA& CMyList::GetAt(POSITION pos)
{
	POSITION p = m_pHead;
	while(p)
	{
		if(p == pos)
			break;
		p = p->pNext;
	}
	return p->data ;
}
POSITION CMyList::GetHeadPosition()
{
	return m_pHead;
}
DATA& CMyList::GetNext(POSITION pos)
{
	return DATA();
}


/*
int& CMyList::FindIndex(DATA data, POSITION StratAfter)
{
	int i = 0;
	int *p = &i;
	return i;
}

template <typename DATA>
const DATA& CMyList<DATA>::GetAt(POSITION pos) const
{
	return DATA();
}



template <typename DATA>
DATA& CMyList<DATA>::GetHead(void)
{
	return DATA();
	//TODO: insert return statement here
}
template <typename DATA>
const DATA& CMyList<DATA>::GetHead(void) const
{
	return DATA();
	//TODO: insert return statement here
}
*/






