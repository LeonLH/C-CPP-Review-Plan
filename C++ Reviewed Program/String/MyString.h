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
	//构造函数的种类较多：
	MyString(void);
	MyString(const MyString& str);				//拷贝构造
	MyString(const char* psz);					//根据字符串常量初始化
	MyString(char ch,int nRepeat = 1);			//n个ch
	MyString(const char *cstr,int nLen);		//cstr的前nLen位

	~MyString(void);
	//基本属性
	int GetLength()
	{
		return m_nLength;
	}

	//增
	int Insert(int iIndex,const char* psz);
	//删
	int Remove(char ch);
	int Delete(int iIndex,int nCount = 1);
	//查
	int Find(const char *pszSub,int iStart = 0);
	int Find(char ch,int iStart =0);
	//改
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
	//单目运算符[]、()
	char operator[](int nIndex)const;
	char& operator[](int nIndex);
	operator const char* ();
	//双目运算符=、+、+=
	char operator+(const char* psz);
	char operator=(const char* psz);
	char operator+=(const char* psz);
	//比较运算符 >  <  >=  <=  ==  !=
	//friend bool operator > (const MyString& psz1,const MyString& psz2);	//虽然operator>是全局性质的函数，但是友元的作用就是对这个函数开放对象内的私有成员变量
	//friend bool operator < (const MyString& psz1,const MyString& psz2);	
	//friend bool operator >= (const MyString& psz1,const MyString& psz2);	
	//friend bool operator <= (const MyString& psz1,const MyString& psz2);	
	//friend bool operator == (const MyString& psz1,const MyString& psz2);	
	//friend bool operator != (const MyString& psz1,const MyString& psz2);	

	//比较运算符 >  <  >=  <=  ==  !=
	friend bool operator > (const MyString& psz1,const MyString& psz2)//虽然operator>是全局性质的函数，但是友元的作用就是对这个函数开放对象内的私有成员变量
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

