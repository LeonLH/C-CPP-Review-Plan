#include<stdio.h>
#include"Stud.h"
void Load()
{//1.�����ݽṹ��ȡ�����ܴﵽ�ܺõı�дҪ��2.�������ļ��д����ݶ�����ָ�룬��Ϊÿһ������ָ����ָ��ĵ�ַ���ᶼ��ͬ
//ע��fopen������������Ĺ��ܣ���Ҫ�У�r w a r+ w+ a+)
 	FILE *fp = fopen("StudInfo.LH","r");
	if(!fp)
		return;
	SNode *p = new SNode,*q;
	p -> pNext = 0;
	g_pHead = p;

	int i = 0;
	while(fread(&(p->data),1,sizeof(DATA),fp) == sizeof(DATA))
	{
		SNode *pNew = new SNode;
		pNew ->pNext = 0;

		p -> pNext = pNew ;
		q = p;
		p = p-> pNext;

		++i;
	}
	q -> pNext = 0;
//	delete pNew;

	if(i == 0)
		g_pHead = 0;

	fclose(fp);
}
void RemoveALL()
{
	SNode *p =g_pHead;
	SNode *q = 0;
	while(p)
	{
		q = p;
		p = p->pNext;
		delete q;
	}
	g_pHead = 0;
}
void Save()
{
	FILE *fp = fopen("StudInfo.LH","w");
	SNode *p = g_pHead;
	int i = 0;

	while(p)
	{
		fwrite(&(p->data),1,sizeof(DATA),fp);
		p = p-> pNext;
		++i;
	}
	fclose(fp);
	RemoveALL();

}
