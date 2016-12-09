#include<stdio.h>

void TestStdio()
{
	char i=100 ;
	getchar();
	i = getchar();
	putchar(i);
	fflush(stdin);
	i = getc(stdin);
	putchar(i);
	fflush(stdin);
	char *p = &i;
	gets(p);
	putchar(i);
	puts("\n");
	putc(i,stdout);

}
