#pragma once

typedef struct DATA 
{

}VALUE;
typedef int KEY;
struct SNode
{
	VALUE Val;
	KEY Key;
	SNode* pLeft;
	SNode* pRight;
};

typedef void* POSITION;
class MyTreeMap
{
	SNode *m_pRoot;

public:
	MyTreeMap(void);
	~MyTreeMap(void);
	bool IsEmpty(void);
	int GetCount(void);
	int GetSize(void);
	POSITION GetStartPosition(void);
	void InitBinTree(void);


	bool Lookup(KEY key, VALUE& rValue);
	
	void RemoveAll(void);
	bool RemoveKey(KEY key);
	
	void SetAt(KEY key, VALUE NewValue);
	VALUE& operator[](KEY key);
};

