#include<string.h>

void main()
{
	char* pstr1 = "hello";
	char *pstr2 = new char[5];
	strcpy_s(pstr2,5,pstr1);
	delete pstr2;
}
