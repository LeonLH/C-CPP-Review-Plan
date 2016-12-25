#pragma once

typedef struct DATA 
{
	float fX;
	DATA():fX(0)
	{
	}


}VALUE;
typedef int KEY;
struct SNode
{
	VALUE Val;
	KEY Key;
	SNode* pLeft;
	SNode* pRight;
	SNode(VALUE v,KEY k)
	{
		Val = v;
		Key = k;
		pLeft = pRight = nullptr;
	}
	~SNode()
	{	pLeft = pRight = nullptr; }


};

typedef void* POSITION;
class MyTreeMap
{
	SNode *m_pRoot;
	POSITION GetNodePosition(KEY key);
public:
	MyTreeMap(void);
	~MyTreeMap(void);
	bool IsEmpty(void);

	bool Lookup(KEY key, VALUE& rValue);
	bool MyTreeMap::Lookup(SNode *pNode ,KEY key,VALUE &rValue);
	void RemoveAll(void);	//清空树
	void RemoveAll(SNode *pNode);	//清空某一子树
	bool RemoveKey(KEY key);		//删除某一键值
	void SetAt(KEY key, VALUE NewValue);
	VALUE& operator[](KEY key);



/*
	int GetCount(void);
	int GetSize(void);
	POSITION GetStartPosition(void);
	void InitBinTree(void);
*/

};

