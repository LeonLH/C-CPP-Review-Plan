//����CArray��˵��һ�¼���Ƚ���Ҫ����Supports arrays that are like C arrays, but can dynamically reduce and grow as necessary.��
//1.CArray�еĽڵ�SNode��ֻҪ����DATA
//2.CArray�ĳ�Ա������Ҫ��������m_nCount/m_nSize/m_pData
//3.��Ҫ���յĳ�Ա������д��
//�������ӣ�ReMalloc() ����Add()/Append() ɾ��RemoveAt()/RemoveAll() �ģ�SetAt() �飺operater []  ������for(i=0,i<m_nCount,++i) GetAt()