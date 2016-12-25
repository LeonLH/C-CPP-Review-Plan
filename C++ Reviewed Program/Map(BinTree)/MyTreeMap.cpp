#include "MyTreeMap.h"


MyTreeMap::MyTreeMap(void)
{
	m_pRoot = nullptr;
}


MyTreeMap::~MyTreeMap(void)
{
	RemoveAll();
}


bool MyTreeMap::IsEmpty(void)
{
	if(!m_pRoot)
		return true;
	else
		return false;
}
//λ��
POSITION MyTreeMap::GetNodePosition(KEY key)
{
	SNode *p = m_pRoot;
	while(p)
	{
		if(key == p->Key )
		{
			return p;
		}
		if(key < p->Key)
			p = p->pLeft;
		/*����д������
			if(p->pLeft)
				p= p->pLeft;
			else
				return false;	
		*/
		if(key > p->Key)
			p = p->pRight;
		/*
			if(p->pRight)
				p= p->pRight;
			else
				return false;
		*/
	}
	return p;
	
}



//��
//�õݹ�ķ������������
bool MyTreeMap::Lookup(KEY key, VALUE& rValue)
{
	SNode *p = m_pRoot;
	if(!p)
		return false;
	return Lookup(p,key,rValue);

}
bool MyTreeMap::Lookup(SNode *pNode ,KEY key,VALUE &rValue)
{//���������key���ڡ�С�ڡ�����
//����������£�����������������������˳����ɣ���< Ȼ��== ���>�����������˳����ɣ���< Ȼ��> ���==��
	if(key == pNode->Key)
	{
		rValue = pNode->Val;
		return true;
	}
	if(key < pNode->Key)
	{
		if(pNode->pLeft)
			return Lookup(pNode->pLeft,key,rValue);

	}
	if(key > pNode->Key)
	{
		if(pNode->pRight)
			return Lookup(pNode->pRight,key,rValue);
	}
	return false;
}
/*
//��ѭ���ķ������������
bool MyTreeMap::Lookup(KEY key, VALUE& rValue)
{
	SNode *p = m_pRoot;
	if(!p)
		return false;
	while(p)
	{
		if(key == p->Key )
		{
			rValue = p->Val;
			return true;
		}
		if(key < p->Key)
			p = p->pLeft;
		//����д������
		//	if(p->pLeft)
		//		p= p->pLeft;
		//	else
		//		return false;	
		//
		if(key > p->Key)
			p = p->pRight;
		//
		//	if(p->pRight)
		//		p= p->pRight;
		//	else
		//		return false;
		//
	}
	return false;
}
*/


//ɾ
void MyTreeMap::RemoveAll(void)
{
	RemoveAll(m_pRoot);
}
void MyTreeMap::RemoveAll(SNode * pSNode)
{
	if( pSNode->pLeft && pSNode->pRight )
		delete pSNode;		//operater delete�������ǵ�������ָ��Ķ���ĵ�����������If exists and always exists��,���Ұ�ָ����Ϊnullptr��
	if(pSNode->pLeft)
		RemoveAll(pSNode->pLeft);
	if(pSNode->pRight)
		RemoveAll(pSNode->pRight);
}

bool MyTreeMap::RemoveKey(KEY key)
{//��Ϊ�������
//1.��������ֱ��ɾ��
//2.�������������������ҵ�key�������������key��Ϊ������key
	SNode *p = (SNode*)GetNodePosition(key);
	if(!p)
		return false;
	if(!p->pLeft && !p->pRight)
	{
		delete p;
		return true;
	}
	//Ѱ������������key
	SNode *pi;
	if(p->pLeft)
	{

		pi = p->pLeft;
		while(pi)
		{
			if(!pi->pRight)
				break;
			pi = pi->pRight;
		}
	}
	else
	{
		pi = p->pRight;
		while(pi)
		{
			if(!pi->pLeft)
				break;
			pi = pi->pLeft;
		}
	}
	//�滻
	p->Key = pi->Key;
	p->Val = pi->Val;
	delete pi;
	return true;
}



//�ġ���
void MyTreeMap::SetAt(KEY key, VALUE NewValue)
{
	(*this)[key] = NewValue;
}


VALUE& MyTreeMap::operator[](KEY key)
{
	SNode *p = m_pRoot,*q = nullptr;
	while(p)	//Tree�д���ĳ��key����ʵ��
	{
		if(p->Key == key)
			return p->Val;
		if(key < p->Key )
			{q = p,	p = p->pLeft;}
		else
			{q = p, p = p->pRight;}
	}
	VALUE v;
	if(!q)	//����
	{
		m_pRoot = new SNode(v,0);
		return m_pRoot->Val;
	}

	if(key< q->Key)		//�ǿ������Ҳ�������ȵ�ʵ��
	{
		q->pLeft = new SNode(v,key);
		return q->pLeft->Val;
	}
	else
	{
		q->pRight = new SNode(v,key);
		return q->pRight->Val;
	}
}



