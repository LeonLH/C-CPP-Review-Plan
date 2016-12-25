#include "MyString.h"

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
	return 0;

}
int MyString::Delete(int iIndex,int nCount)
{
	return 0;
}
/*	
//��
int MyString::Find(const char *pszSub,int iStart)
{

}

int MyString::Find(char ch,int iStart)
{

}

//��
MyString& MyString::MakeUpper()
{

}

MyString& MyString::MakeLower()
{

}

MyString& MyString::MakeReverse()
{

}


MyString& MyString::Trim(char ch)
{

}

MyString& MyString::Trim(const char *psz)
{

}

MyString& MyString::TrimLeft(char ch)
{

}

MyString& MyString::TrimRight(char ch)
{

}


int MyString::Replace(const char* pszOld,const char* pszNew)
{

}

int MyString::Replace(char chOld,char chNew)
{

}


MyString& MyString::Left(int nCount)
{

}

MyString& MyString::Right(int nCount)
{

}

MyString& MyString::Mid(int iFirst,int nCount)
{

}


//operater
//��Ŀ�����[]��()
char MyString::operator[](int nIndex)const
{

}

char& MyString::operator[](int nIndex)
{

}

MyString::operator const char* ()
{

}

//˫Ŀ�����=��+��+=
char MyString::operator+(const char* psz)
{

}

char MyString::operator=(const char* psz)
{

}

char MyString::operator+=(const char* psz)
{

}


*/