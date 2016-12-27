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
	MyString& Trim();
	MyString& Trim(const char *psz);
	MyString& TrimLeft(const char *psz);
	MyString& TrimLeft(char ch);
	MyString& TrimRight(char ch);
	MyString& TrimRight(const char* psz);
	int Replace(const char* pszOld,const char* pszNew);
	int Replace(char chOld,char chNew);

	MyString& Left(int nCount) const;
	MyString& Right(int nCount) const;
	MyString& Mid(int iFirst,int nCount) const;

	//operater
	//��Ŀ�����[]��()
	char operator[](int nIndex)const;
	char& operator[](int nIndex);
	operator const char* () const;
	operator const char*();

	//˫Ŀ�����=��+��+=		//Ҳ����ʹ����Ԫ�Ĺ����������±߱Ƚ�������ı�д
	MyString& MyString::operator+(const MyString& str1);
	MyString& MyString::operator=(const MyString& str1);
	MyString& MyString::operator+=(const MyString& str1);
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
		return strcmp(psz1,psz2)>0;
	}

	friend bool operator < (const MyString& psz1,const MyString& psz2)
	{
		return strcmp(psz1,psz2)<0;
	}

	friend bool operator >= (const MyString& psz1,const MyString& psz2)
	{
		return strcmp(psz1,psz2)>=0;
	}

	friend bool operator <= (const MyString& psz1,const MyString& psz2)
	{
		return strcmp(psz1,psz2)<=0;
	}

	friend bool operator == (const MyString& psz1,const MyString& psz2)
	{
		return strcmp(psz1,psz2)==0;
	}

	friend bool operator != (const MyString& psz1,const MyString& psz2)
	{
		return strcmp(psz1,psz2)!=0;
	}
};

