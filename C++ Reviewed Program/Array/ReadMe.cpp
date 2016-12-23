//对于CArray来说有一下几点比较重要：（Supports arrays that are like C arrays, but can dynamically reduce and grow as necessary.）
//1.CArray中的节点SNode中只要数据DATA
//2.CArray的成员变量主要有三个：m_nCount/m_nSize/m_pData
//3.需要掌握的成员函数编写：
//容量增加：ReMalloc() 增：Add()/Append() 删：RemoveAt()/RemoveAll() 改：SetAt() 查：operater []  遍历：for(i=0,i<m_nCount,++i) GetAt()