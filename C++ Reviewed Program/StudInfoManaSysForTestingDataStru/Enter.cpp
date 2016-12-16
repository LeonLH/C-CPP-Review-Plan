#include<iostream>
#include"HEAD.h"



void main()
{
	system("color 3f");
	Welcome();
	Load();
	while(Menu())
		;
	Save();
	return;
}
