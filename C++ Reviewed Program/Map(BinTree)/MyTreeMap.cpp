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
//位置
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
		/*简略写法如上
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



//查
//用递归的方法先序遍历：
bool MyTreeMap::Lookup(KEY key, VALUE& rValue)
{
	SNode *p = m_pRoot;
	if(!p)
		return false;
	return Lookup(p,key,rValue);

}
bool MyTreeMap::Lookup(SNode *pNode ,KEY key,VALUE &rValue)
{//三种情况，key等于、小于、大于
//先序遍历如下，中序遍历就是下述三种情况顺序调成（先< 然后== 最后>），后序遍历顺序调成（先< 然后> 最后==）
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
//用循环的方法先序遍历：
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
		//简略写法如上
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


//删
void MyTreeMap::RemoveAll(void)
{
	RemoveAll(m_pRoot);
}
void MyTreeMap::RemoveAll(SNode * pSNode)
{
	if( pSNode->pLeft && pSNode->pRight )
		delete pSNode;		//operater delete的作用是调用它所指向的对象的的析构函数（If exists and always exists）,并且把指针置为nullptr。
	if(pSNode->pLeft)
		RemoveAll(pSNode->pLeft);
	if(pSNode->pRight)
		RemoveAll(pSNode->pRight);
}

bool MyTreeMap::RemoveKey(KEY key)
{//分为以下情况
//1.无子树，直接删除
//2.有子树，以左子树最右的key或右子树最左的key作为子树的key
	SNode *p = (SNode*)GetNodePosition(key);
	if(!p)
		return false;
	if(!p->pLeft && !p->pRight)
	{
		delete p;
		return true;
	}
	//寻找左子树最右key
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
	//替换
	p->Key = pi->Key;
	p->Val = pi->Val;
	delete pi;
	return true;
}



//改、增
void MyTreeMap::SetAt(KEY key, VALUE NewValue)
{
	(*this)[key] = NewValue;
}


VALUE& MyTreeMap::operator[](KEY key)
{
	SNode *p = m_pRoot,*q = nullptr;
	while(p)	//Tree中存在某个key等于实参
	{
		if(p->Key == key)
			return p->Val;
		if(key < p->Key )
			{q = p,	p = p->pLeft;}
		else
			{q = p, p = p->pRight;}
	}
	VALUE v;
	if(!q)	//空树
	{
		m_pRoot = new SNode(v,0);
		return m_pRoot->Val;
	}

	if(key< q->Key)		//非空树，且不存在相等的实参
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



