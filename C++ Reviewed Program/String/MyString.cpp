#include "MyString.h"
#pragma warning (disable:4996)
//���캯���бȽ϶�����࣬��Ҫע�⣺
MyString::MyString(void)
{
	m_pData = new char[1];
	m_pData[0] = '\0';
	m_nLength = 0;

}
MyString::MyString(const MyString& str)				//��������
{
	m_nLength = str.m_nLength;
	m_pData = new char[m_nLength+ 1];
	memcpy(m_pData,str.m_pData,sizeof(char)*(m_nLength+1));
}

MyString::MyString(const char* psz)					//�����ַ���������ʼ��
{
	m_nLength = strlen(psz);
	m_pData = new char[m_nLength+1];
	strcpy_s(m_pData,m_nLength+1,psz);
}

MyString::MyString(char ch,int nRepeat)			//n��ch
{
	m_nLength = nRepeat;
	m_pData = new char[m_nLength + 1];
	m_pData[m_nLength] = 0;
	while(m_nLength--)
		m_pData[m_nLength] = ch;

}

MyString::MyString(const char *cstr,int nLen)		//cstr��ǰnLenλ
{
	int n = strlen(cstr);
	m_nLength = (n<nLen?n:nLen);
	m_pData = new char[m_nLength+1];
	strcpy(m_pData,cstr);
	m_pData[m_nLength] = 0;


}


MyString::~MyString(void)
{
	delete []m_pData;
}

//��
int MyString::Insert(int iIndex,const char* psz)
{
	int n = strlen(psz);
	char *pNew = new char[m_nLength+n+1];
	strcpy_s(pNew,iIndex,m_pData);
	strcpy_s(pNew+iIndex,n,psz);
	strcpy_s(pNew+iIndex+n,m_nLength-iIndex,m_pData+iIndex);
	pNew[m_nLength+n] = 0;
	delete []m_pData;
	m_pData = pNew;
	m_nLength += n;
	return m_nLength;
}

//ɾ
int MyString::Remove(char ch)
{
	int n = 0,i=0;	//N for Counting
	while(m_pData[i])
	{
		++i;
		if(m_pData[i] == ch)
			++n;
	}
	if(!n)
		return 0;
	char *pstr = new char[m_nLength-n+1];
	i = 0;
	int j = 0;
	while(m_pData[i])
	{
		if(m_pData[i] != ch)
		{
			pstr[j] = m_pData[i];
			++j;
		}
		++i;
	}
	pstr[j] = 0;
	delete []m_pData;
	m_pData = pstr;
	m_nLength -= n;
	return n;
}
int MyString::Delete(int iIndex,int nCount)
{
	nCount = (nCount<(m_nLength-iIndex)?nCount:(m_nLength-iIndex));
	char *pstr = new char[m_nLength - nCount + 1];
	strcpy_s(pstr,iIndex,m_pData);
	strcpy_s(pstr+iIndex,m_nLength-iIndex-nCount,m_pData+iIndex+nCount);
	pstr[m_nLength-nCount] = 0;
	delete []m_pData;
	m_pData = pstr;
	m_nLength -= nCount;
	return m_nLength;
}

//��
int MyString::Find(const char *pszSub,int iStart)
{
	int n = m_nLength;
	int i = iStart;
	int nLen = strlen(pszSub);
	while(i<n)
	{
		if(m_pData[i] == pszSub[0])
		{
			char *str = m_pData+i;
			str[nLen] = 0;
			if(!strcmp(str,pszSub))
				return i;
		}
		++i;
	}
	return -1;
			
}

int MyString::Find(char ch,int iStart)
{
	int n = m_nLength;
	while(iStart<n)
	{
		if(m_pData[iStart] == ch)
			return iStart;
		++iStart;
	}
	return -1;
}

//��
MyString& MyString::MakeUpper()
{
	int n = m_nLength;
	while(n--)
	{
		if(m_pData[n] > 'a' && m_pData[n] < 'z')
			m_pData[n] -= 32; 
	}
	return *this;
}

MyString& MyString::MakeLower()
{
	int n = m_nLength;
	while(n--)
	{
		if(m_pData[n] > 'A' && m_pData[n] < 'Z')
			m_pData[n] += 32; 
	}
	return *this;

}

MyString& MyString::MakeReverse()
{
	int n = 0;
	char ctmp = 0;
	while(n<m_nLength/2)
	{
		ctmp = m_pData[n];
		m_pData[n] = m_pData[m_nLength-n-1];
		m_pData[m_nLength-n-1] = ctmp;
	}
	return *this;
}

//Trim
MyString& MyString::Trim(char ch)
{
	TrimLeft(ch);
	TrimRight(ch);
	return *this;
}
MyString& MyString::Trim(const char *psz)
{
	TrimLeft(psz);
	TrimRight(psz);
	return *this;	
}
MyString& MyString::Trim()
{
	Trim(' ');
	return *this;
}

MyString& MyString::TrimLeft(char ch)
{
	int i=0;
	while(m_pData[i++] == ch)
		;
	char *pstr = new char[m_nLength-i+1];
	strcpy(pstr,&m_pData[i]);
	pstr[m_nLength-i] = 0;
	delete []m_pData;
	m_pData = pstr;
	m_nLength -= i;
	return *this;
}
MyString& MyString::TrimLeft(const char *psz)
{
	int i=0;

	while(strchr(psz,m_pData[i]))
	{
		++i;
	}

	char *pstr = new char[m_nLength-i+1];
	strcpy(pstr,&m_pData[i]);
	pstr[m_nLength-i] = 0;
	delete []m_pData;
	m_pData = pstr;
	m_nLength -= i;
	return *this;
}


MyString& MyString::TrimRight(char ch)
{
	int i = m_nLength,n = 0;
	while(m_pData[i-1] == ch)
	{
		--i;
		++n;	//������
	}
	char *pstr = new char[m_nLength-n+1];
	m_pData[m_nLength-n] = 0;
	strcpy(pstr,&m_pData[i]);
	pstr[m_nLength-i] = 0;
	delete []m_pData;
	m_pData = pstr;
	m_nLength -= n;
	return *this;
}

MyString& MyString::TrimRight(const char* psz)
{
	int i = m_nLength,n = 0;
	while(strchr(psz,m_pData[i-1]))
	{
		--i;
		++n;	//������
	}
	char *pstr = new char[m_nLength-n+1];
	m_pData[m_nLength-n] = 0;
	strcpy(pstr,&m_pData[i]);
	pstr[m_nLength-i] = 0;
	delete []m_pData;
	m_pData = pstr;
	m_nLength -= n;
	return *this;
}

//��������Ƚϸ�����Ҫ�ر�ע�⣺
int MyString::Replace(const char* pszOld,const char* pszNew)
{
	int i = 0,n = 0;
	int nLenOld = strlen(pszOld);
	int nLenNew = strlen(pszNew);
	char *pstrtmp = new char[nLenOld+1];
	//�Ȼ����ԭ�ַ������м����Ӵ����Ա�ȷ�����ַ����ĳ���
	while(i<m_nLength)
	{
		if(m_pData[i] == pszOld[0])
		{
			strcpy_s(pstrtmp,nLenOld,&m_pData[i]);
			if(!strcmp(pstrtmp,pszOld))
				++n;
		}
		++i;
	}
	char *pNew = new char[m_nLength+(nLenNew-nLenOld)*n+1];
	i = 0;		//iΪԭ�����±�
	int j = 0;	//jΪ�´����±�
	while(i<m_nLength)
	{
		if(m_pData[i] == pszOld[0])
		{
			strcpy_s(pstrtmp,nLenOld,&m_pData[i]);
			if(!strcmp(pstrtmp,pszOld))
			{
				strcpy_s(&pNew[j],nLenNew,pszNew);
				j += nLenNew;
			}
		}
		pNew[j] = m_pData[i];
		++i;
		++j;
	}
	delete []m_pData;
	m_pData = pNew;
	m_nLength = m_nLength+(nLenNew-nLenOld)*n;
	m_pData[m_nLength] = 0;
	return n;
}

int MyString::Replace(char chOld,char chNew)
{
	int i = 0,n = 0;
	while(i<m_nLength)
	{
		if(m_pData[i] == chOld)
		{
			m_pData[i] = chNew;
			++n;
		}
		++i;
	}
	return n;
}

//��ȡ��Extract��
MyString& MyString::Left(int nCount) const
{
	char *pstr = new char[nCount+1]; 
	if(nCount >= m_nLength)
		return (MyString)(*this);
	int n = nCount;
	while(n--)
		pstr[n] = m_pData[n];
	pstr[nCount] = 0;
	return (MyString)pstr;	
}

MyString& MyString::Right(int nCount) const
{
	char *pstr = new char[nCount+1]; 
	if(nCount >= m_nLength)
		return (MyString)(*this);
	int n = nCount,i = 0;
	while(i<nCount)
	{
		pstr[i] = m_pData[m_nLength-n+i];
		++i;
	}
	pstr[nCount] = 0;
	MyString str = pstr;
	return str;	
}

MyString& MyString::Mid(int iFirst,int nCount) const
{
	
	char *pstr = new char[nCount+1]; 
	int n = (nCount < (m_nLength-iFirst) ? nCount:(m_nLength-iFirst));
	int i = 0;
	while(i<n)
	{
		pstr[i] = m_pData[m_nLength-n+i];
		++i;
	}
	pstr[nCount] = 0;
	return (MyString)pstr;	


}
/**/
/**/
//operater
//��Ŀ�����[]��()
char MyString::operator[](int nIndex)const
{
	return m_pData[nIndex];
}

char& MyString::operator[](int nIndex)
{
	return m_pData[nIndex];
}

MyString::operator const char* () const
{
	return m_pData;
}
MyString::operator const char*()
{
	return m_pData;
}

/**/
//˫Ŀ�����=��+��+=
MyString& MyString::operator+(const MyString& str1)
{
	MyString strNew;
	int nLen = m_nLength + str1.m_nLength;
	delete []strNew.m_pData;
	strNew.m_pData = new char[nLen+1];
	strcpy_s(strNew.m_pData,m_nLength,m_pData);
	strcpy_s(strNew.m_pData+m_nLength,str1.m_nLength,str1.m_pData);
	strNew.m_pData[nLen] = 0;
	return strNew;

}

MyString& MyString::operator=(const MyString& str1)
{
	delete []m_pData;
	m_nLength = str1.m_nLength;
	m_pData = new char[str1.m_nLength+1];
	strcpy_s(m_pData,m_nLength,str1.m_pData);
	return *this;
}

MyString& MyString::operator+=(const MyString& str1)
{
	MyString str;
	str.m_nLength = str1.m_nLength + m_nLength;
	str.m_pData = new char[str.m_nLength+1];
	strcpy_s(str.m_pData,m_nLength,m_pData);
	strcpy_s(str.m_pData+m_nLength,str1.m_nLength,str1.m_pData);
	str.m_pData[m_nLength]= 0;
	return str;

}


