#pragma once



struct DATA
{
	int i;
};
struct SNode
{//�ṹ���Ա�ı����ĳ�ʼ������ʵ������new��֮�����϶����ڲ����еĳ�Ա������ֵ���ṹ��Ķ���
	DATA data;
	SNode *pNext;
	SNode *pPrev;
};

typedef void* POSITION;
class CMyList
{
	SNode* m_pHead;
	SNode* m_pTail;
	int m_nCount;
public:

	CMyList(void);
	~CMyList(void);

	void AddHead(DATA data);
/*	void AddTail(DATA data);
	void InsertAfter(POSITION pos);
	void InsertBefore(POSITION pos);
	void RemoveAt(POSITION pos);
	void RemoveHead(void);
	void RemoveTail(void);
	void RemoveAll(void);
	void SetAt(POSITION pos, DATA data);
	bool IsEmpty(void);
	POSITION Find(DATA data, POSITION StartAfter);
	int& FindIndex(DATA data, POSITION StratAfter);
//	DATA& GetAt(POSITION pos);
//	const DATA& CMyList::GetAt(POSITION pos) const;
//	DATA& GetHead(void);
//	const DATA& CMyList::GetHead(void) const;
*/
};

