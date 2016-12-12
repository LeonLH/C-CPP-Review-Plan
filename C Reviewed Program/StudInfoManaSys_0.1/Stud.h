#include<stdio.h>
#include<stdlib.h>


void Load();
void Save();

void Modify();
void Search();
void Browse();
void Delete();
void Add();
void Print();

struct DATA
{
	int nNumb;
	char sName[20];
	float fMath;

};

struct SNode
{
	DATA data;
	SNode *pNext;
};

extern SNode *g_pHead;