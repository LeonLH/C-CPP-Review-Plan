#include "MyList.h"
#include<list>
using namespace std;



CMyList::CMyList(void)
{
	list l1;

}


CMyList::~CMyList(void)
{
}
bool CMyList::IsEmpty(void)
{
	return false;
}
//增
void AddHead(DATA data)
{

}


void CMyList::AddTail(DATA data)
{
}


void CMyList::InsertAfter(POSITION pos)
{

}


void CMyList::InsertBefore(POSITION pos)
{
}

//删
void CMyList::RemoveAt(POSITION pos)
{
}


void CMyList::RemoveHead(void)
{
}


void CMyList::RemoveTail(void)
{
}


void CMyList::RemoveAll(void)
{
}

//改
void CMyList::SetAt(POSITION pos, DATA data)
{
}
//查

POSITION CMyList::Find(DATA data, POSITION StartAfter)
{
	return POSITION();
}



int& CMyList::FindIndex(DATA data, POSITION StratAfter)
{
	int i = 0;
	int *p = &i;
	return i;
}
//位置


DATA& CMyList::GetAt(POSITION pos)
{
	return DATA();
}

const DATA& CMyList::GetAt(POSITION pos) const
{
	return DATA();
}




DATA& CMyList::GetHead(void)
{
	return DATA();
	//TODO: insert return statement here
}

const DATA& CMyList::GetHead(void) const
{
	return DATA();
	//TODO: insert return statement here
}


