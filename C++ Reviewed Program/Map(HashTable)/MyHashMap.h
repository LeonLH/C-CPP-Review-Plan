#pragma once
#include<memory>

typedef struct DATA
{
	int i;
}VALUE;
typedef int KEY;
struct SNode 
{
	VALUE Val;
	KEY Key;
	SNode *pNext;

};
typedef void* POSITION;

class MyHashMap
{
	SNode **m_pHashTable;
	int m_nHashSize;
	unsigned int m_nCount;
public:
	MyHashMap(int nHashSize = 17);
	~MyHashMap(void);

	bool IsEmpty(void);
	int GetCount(void);
	int GetSize(void);
	int GetHashTableSize(void);
	POSITION GetStartPosition(void);
	void InitHashTable(unsigned nHashSize, bool bAllocNow = true);
	bool Lookup(KEY key, VALUE& rValue);
	void RemoveAll(void);
	bool RemoveKey(KEY key);
	void SetAt(KEY key, VALUE NewValue);
	VALUE& operator[](KEY key);

};

