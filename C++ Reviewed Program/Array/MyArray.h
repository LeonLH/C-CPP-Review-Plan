#pragma once
#include <string.h>
struct DATA
{

};

class MyArray
{
	int m_nCount;	//Ԫ�ظ���
	int m_nSize;	//������С
	DATA *m_pData;
	void ReMalloc(int a);
public:
	MyArray(void);
	~MyArray(void);
	int Add(DATA NewElem);
	int Append(const MyArray& src);
	void RemoveAt(int nIndex , int nCount);
	void RemoveAll();
	const int GetSize() 
	{	return m_nCount+1;	}
	const int GetCount()
	{	return m_nCount+1;	}
	DATA& GetAt(int nIndex)
	{	return m_pData[nIndex];	}
	void SetAt(int nIndex , DATA NewElem)
	{	m_pData[nIndex] = NewElem;	}
	bool IsEmpty()
	{	return (m_nCount ? false : true);	}

	DATA& operator [] (int nIndex)		//������ź�SetAt��������һ����
	{	return m_pData[nIndex];	}


	
};

