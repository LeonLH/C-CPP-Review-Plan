#include<stdio.h>

void TestScanfOverflow()
{
	int i=90;
	double f=768.56;
	char s[4];
	
//	scanf("%d%lf%s",&i,&f,&s);
	scanf_s("%d%lf%s",&i,&f,&s);
	//例如当输入对s输入aaaabbbbccccddddeeeeffffgggghhhh时就会把i和f的内存上都写满，破坏数据

}

void TestScanf_s()
{
	int i=90;
	double f=768.56;
	char s[4];
	scanf_s("%d%lf%s",&i,&f,&s);
//	scanf("%d%lf%s",&i,&f,&s);
}
