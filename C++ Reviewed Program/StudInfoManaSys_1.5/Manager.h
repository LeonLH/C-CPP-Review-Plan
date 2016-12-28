#pragma once
#include <iostream>
#include <afxtempl.h>

typedef struct UserData
{
	int nNumb;
	char sName[20];
	char sPW[20];
	int nPrio;
}TDATA;

class CManager
{
	CArray<TDATA> m_arr;
	bool IsExist(int nNumb);
	bool IsExist(char * sName);
	bool IsPWRight(char *pName,char *pstr);
	int GetIndexFromNumb(int nNumb);
	void PrintNumb(int nNumb);
public:
	CManager(void);
	~CManager(void);
	void Load(void);
	void Save(void);
	bool Login(void);
	int Menu(void);
	void Add(void);
	void Delete(void);
	void Modify();
	void Find(int nNumb);
	void Print(void);
	void Browse();
	
private:
	
public:
	void ChangePassWord(void);
};

