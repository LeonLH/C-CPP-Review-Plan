#include<stdio.h>

void TestScanfOverflow()
{
	int i=90;
	double f=768.56;
	char s[4];
	
//	scanf("%d%lf%s",&i,&f,&s);
	scanf_s("%d%lf%s",&i,&f,&s);
	//���統�����s����aaaabbbbccccddddeeeeffffgggghhhhʱ�ͻ��i��f���ڴ��϶�д�����ƻ�����

}

void TestScanf_s()
{
	int i=90;
	double f=768.56;
	char s[4];
	scanf_s("%d%lf%s",&i,&f,&s);
//	scanf("%d%lf%s",&i,&f,&s);
}
