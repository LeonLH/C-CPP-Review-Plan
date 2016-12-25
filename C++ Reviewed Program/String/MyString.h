#pragma once
#include <string.h>
class MyString
{
	int m_nLength;
	char *m_pData;
	MyString(int nLen)
	{
		m_pData = new char[nLen+1];
		m_nLength = nLen;
	}

public:
	//���캯��������϶ࣺ
	MyString(void);
	MyString(const MyString& str);				//��������
	MyString(const char* psz);					//�����ַ���������ʼ��
	MyString(char ch,int nRepeat = 1);			//n��ch
	MyString(const char *cstr,int nLen);		//cstr��ǰnLenλ

	~MyString(void);
	//��������
	int GetLength()
	{
		return m_nLength;
	}

	//��
	int Insert(int iIndex,const char* psz);
	//ɾ
	int Remove(char ch);
	int Delete(int iIndex,int nCount = 1);
	//��
	int Find(const char *pszSub,int iStart = 0);
	int Find(char ch,int iStart =0);
	//��
	MyString& MakeUpper();
	MyString& MakeLower();
	MyString& MakeReverse();

	MyString& Trim(char ch);
	MyString& Trim(const char *psz);
	MyString& TrimLeft(char ch);
	MyString& TrimRight(char ch);

	int Replace(const char* pszOld,const char* pszNew);
	int Replace(char chOld,char chNew);

	MyString& Left(int nCount);
	MyString& Right(int nCount);
	MyString& Mid(int iFirst,int nCount);

	//operater
	//��Ŀ�����[]��()
	char operator[](int nIndex)const;
	char& operator[](int nIndex);
	operator const char* ();
	//˫Ŀ�����=��+��+=
	char operator+(const char* psz);
	char operator=(const char* psz);
	char operator+=(const char* psz);
	//�Ƚ������ >  <  >=  <=  ==  !=
	//friend bool operator > (const MyString& psz1,const MyString& psz2);	//��Ȼoperator>��ȫ�����ʵĺ�����������Ԫ�����þ��Ƕ�����������Ŷ����ڵ�˽�г�Ա����
	//friend bool operator < (const MyString& psz1,const MyString& psz2);	
	//friend bool operator >= (const MyString& psz1,const MyString& psz2);	
	//friend bool operator <= (const MyString& psz1,const MyString& psz2);	
	//friend bool operator == (const MyString& psz1,const MyString& psz2);	
	//friend bool operator != (const MyString& psz1,const MyString& psz2);	

	//�Ƚ������ >  <  >=  <=  ==  !=
	friend bool operator > (const MyString& psz1,const MyString& psz2)//��Ȼoperator>��ȫ�����ʵĺ�����������Ԫ�����þ��Ƕ�����������Ŷ����ڵ�˽�г�Ա����
	{

	}

	friend bool operator < (const MyString& psz1,const MyString& psz2)
	{

	}

	friend bool operator >= (const MyString& psz1,const MyString& psz2)
	{

	}

	friend bool operator <= (const MyString& psz1,const MyString& psz2)
	{

	}

	friend bool operator == (const MyString& psz1,const MyString& psz2)
	{

	}

	friend bool operator != (const MyString& psz1,const MyString& psz2)
	{

	}
};

