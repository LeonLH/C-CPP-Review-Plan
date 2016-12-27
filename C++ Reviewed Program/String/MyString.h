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
	//单目运算符[]、()
	char operator[](int nIndex)const;
	char& operator[](int nIndex);
	operator const char* () const;
	operator const char*();

	//双目运算符=、+、+=		//也可以使用友元的功能类似于下边比较运算符的编写
	MyString& MyString::operator+(const MyString& str1);
	MyString& MyString::operator=(const MyString& str1);
	MyString& MyString::operator+=(const MyString& str1);
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

