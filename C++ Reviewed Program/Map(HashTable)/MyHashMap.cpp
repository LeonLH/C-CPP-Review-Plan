#include "MyHashMap.h"

//�൱����InitHashTable(17,true)
MyHashMap::MyHashMap(int nHashSize)
	: m_nCount(0)
{
	m_nHashSize = nHashSize;
	m_pHashTable = new SNode*[m_nHashSize];
	memset(m_pHashTable,0,sizeof(SNode*)*m_nHashSize);
}


MyHashMap::~MyHashMap(void)
{
	RemoveAll();
	m_nCount = 0;
}



int MyHashMap::GetHashTableSize(void)
{

	return m_nHashSize;
}


POSITION MyHashMap::GetStartPosition(void)
{
	return POSITION();
}

//��ʼ�������þ��ǽ���һ���յ�HashTable��ָ��HashSize
void MyHashMap::InitHashTable(unsigned nHashSize, bool bAllocNow) //����Ϊfalseʱ��ʲôʵ�֣�
{
	if(m_pHashTable)
	{
		delete [] m_pHashTable;
		m_pHashTable = 0;
	}
	m_nHashSize = nHashSize;
	if(bAllocNow)
	{
		m_pHashTable = new SNode* [nHashSize];
		memset(m_pHashTable,0,sizeof(SNode*)*nHashSize);
	}
	m_nCount = 0;
}


//��
bool MyHashMap::Lookup(KEY key, VALUE& rValue)
{
	int n = key%m_nHashSize;
	SNode *p = m_pHashTable[n];
	while(p)
	{
		if(p->Key == key )
		{
			rValue = p -> Val;
			return true;
		}

		p = p->pNext;
	}
	if(!p)
		return false;
}
//�����ģ�������Ҳ�������β����ӣ����ҵ��򸲸�ԭ����
void MyHashMap::SetAt(KEY key, VALUE NewValue)
{
	int n = key%m_nHashSize;
	SNode* p = m_pHashTable[n];
	SNode* q;

	while(p)
	{
		if(p->Key == key)
		{
			p->Val = NewValue;
			break;
		}
		q = p;
		p = p->pNext;
	}
	if(!p)
	{
		p = new SNode;
		p->Key = key;
		p->Val = NewValue;
		p->pNext = nullptr;
		q->pNext = p;
		m_nCount += 1;
	}
}


VALUE& MyHashMap::operator[](KEY key)	//convenient substitute for the SetAt
{
	int n = key%m_nHashSize;
	SNode* p = m_pHashTable[n];
	SNode* q;

	while(p)
	{
		if(p->Key == key)
			return p->Val;
		q = p;
		p = p->pNext;
	}
	if(!p)
	{
		p = new SNode;
		p->Key = key;
		p->pNext = nullptr;
		q->pNext = p;
		return p->Val;
		m_nCount += 1;
	}
	//TODO: insert return statement here
}


//ɾ�ͷ��������пռ䣨����ָ�������ÿһ�������������ݣ�
void MyHashMap::RemoveAll(void)
{
	int n = m_nHashSize;
	while(n)
	{
		SNode *p = m_pHashTable[n-1];
		SNode *q;
		while(p)
		{
			q = p;
			p = p->pNext;
			delete q;
		}
		--n;
	}
	m_nCount = 0;
	delete []m_pHashTable;
	m_pHashTable = nullptr;

}


bool MyHashMap::RemoveKey(KEY key)
{
	int n = m_nHashSize;
	SNode *p = m_pHashTable[n];
	SNode *q = nullptr;
	while(p)
	{
		if(p->Key == key)
		{
			if(!q)
			{
				m_pHashTable[n] = p->pNext;
				delete p;
			}
			q->pNext = p->pNext;
			delete p;
			m_nCount -= 1;
			return true;
		}
		q = p;
		p = p->pNext;
	}
	return false;
}






bool MyHashMap::IsEmpty(void)
{
	if(m_nCount)
		return false;
	return true;
}


int MyHashMap::GetCount(void)
{
	return m_nCount;
}


int MyHashMap::GetSize(void)
{
	return m_nCount;

}
