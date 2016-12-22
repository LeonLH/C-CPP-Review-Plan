#include "MyList.h"


CMyList::CMyList(void)
{
	m_pHead = nullptr;
	m_pTail = nullptr;
	m_nCount = 0;
}

CMyList::~CMyList(void)
{

}
//增
void CMyList::AddHead(DATA data)
{
	if(!m_pHead)
	{
		SNode *pNew = new SNode;
		m_pHead = pNew;
		m_pTail = pNew;
	}
	SNode *pNew = new SNode;
	pNew -> pNext = m_pHead;
	pNew -> data = data;
	m_pHead = pNew;
}
/*
template <typename DATA>
bool CMyList<DATA>::IsEmpty(void)
{
	if(!m_pHead )
		return true;
	return false;
}
template <typename DATA>
void CMyList<DATA>::AddTail(DATA data)
{
	if(!m_pTail)
	{
		SNode<DATA> *pNew = new SNode<DATA>;
		m_pHead = pNew;
		m_pTail = pNew;
	}
	SNode<DATA> *pNew = new SNode<DATA>;
	m_pTail -> pNext = pNew;
	pNew -> data = data;
	m_pTail = pNew;
}

template <typename DATA>
void CMyList<DATA>::InsertAfter(POSITION pos)
{
	POSITION p = m_pHead;
	while(p)

}

template <typename DATA>
void CMyList<DATA>::InsertBefore(POSITION pos)
{
}

//删
template <typename DATA>
void CMyList<DATA>::RemoveAt(POSITION pos)
{
}

template <typename DATA>
void CMyList<DATA>::RemoveHead(void)
{
}

template <typename DATA>
void CMyList<DATA>::RemoveTail(void)
{
}

template <typename DATA>
void CMyList<DATA>::RemoveAll(void)
{
}

//改
template <typename DATA>
void CMyList<DATA>::SetAt(POSITION pos, DATA data)
{
}
//查
template <typename DATA>
POSITION CMyList<DATA>::Find(DATA data, POSITION StartAfter)
{
	return POSITION();
}


template <typename DATA>
int& CMyList<DATA>::FindIndex(DATA data, POSITION StratAfter)
{
	int i = 0;
	int *p = &i;
	return i;
}
//位置

template <typename DATA>
DATA& CMyList<DATA>::GetAt(POSITION pos)
{
	return DATA();
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

