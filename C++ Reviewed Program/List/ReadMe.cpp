//对于CList来说有一下几点比较重要：
//1.CList中的节点SNode是由数据（DATA）和pNext/pPrev两个指针组成的；
//2.CList的成员变量主要有三个：m_nCount/m_pHead/m_pTail
//3.CList遍历主要有以下两种方法：
//		1.利用POSITION pos为迭代器，初值GetHeadPosition(),pos = GetNext(pos) 直到条件pos=0；
//		2.for(i=0,i<m_nCount,++i)	//这种不常用
//4.需要掌握的成员函数编写：
//增：AddHead()/AddTail() 删：RemoveAt()/RemoveAll() 改：SetAt() 查：Find() 遍历：POSITION GetHeadPosition() GetNext() GetAt()