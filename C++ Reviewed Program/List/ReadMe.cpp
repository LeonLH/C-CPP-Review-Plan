//����CList��˵��һ�¼���Ƚ���Ҫ��
//1.CList�еĽڵ�SNode�������ݣ�DATA����pNext/pPrev����ָ����ɵģ�
//2.CList�ĳ�Ա������Ҫ��������m_nCount/m_pHead/m_pTail
//3.CList������Ҫ���������ַ�����
//		1.����POSITION posΪ����������ֵGetHeadPosition(),pos = GetNext(pos) ֱ������pos=0��
//		2.for(i=0,i<m_nCount,++i)	//���ֲ�����
//4.��Ҫ���յĳ�Ա������д��
//����AddHead()/AddTail() ɾ��RemoveAt()/RemoveAll() �ģ�SetAt() �飺Find() ������POSITION GetHeadPosition() GetNext() GetAt()