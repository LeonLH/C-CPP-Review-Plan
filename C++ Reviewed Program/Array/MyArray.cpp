#include "MyArray.h"


MyArray::MyArray(void)
{
	m_pData = new DATA[m_nSize = 5];
	m_nCount = 0;
}


MyArray::~MyArray(void)
{
	delete []m_pData;
}

void MyArray::ReMalloc(int n)
{
	DATA *pNew = new DATA[m_nSize * 2];
	memcpy(pNew ,m_pData,sizeof(DATA)*m_nSize);
	delete []m_pData;
	m_pData = pNew;
	m_nSize *= 2;
}

int MyArray::Add(DATA NewElem)
{
	while(m_nCount >= m_nSize)
		ReMalloc(m_nSize);
	m_pData[m_nCount] = NewElem;
	m_nCount += 1;
	return m_nCount-1;
}


int MyArray::Append(const MyArray& src)
{//×·¼Ó
	while(m_nCount+src.m_nCount >= m_nSize)
		ReMalloc(m_nSize);
	memcpy(&m_pData[m_nCount],src.m_pData,sizeof(DATA)*src.m_nCount);
	m_nCount += src.m_nCount;
	return m_nCount-src.m_nCount;
}

void MyArray::RemoveAt(int nIndex , int nCount)
{
	memcpy(&m_pData[nIndex],&m_pData[nIndex+nCount],sizeof(DATA)*(m_nCount-nIndex-nCount));
	m_nCount -= nCount;
}

void MyArray::RemoveAll()
{
	m_nCount = 0;
}
