#include<stdio.h>
#include<stdlib.h>

void TestAtoi()
{
	char *str = NULL;
	str = "1234";
	int i = atoi(str);
	str ="-1234";
	 i = atoi(str);
//	float f = 0.0;
	char *str1 = NULL;

	str1 = "1234.5678265432128456";
	double f = atof(str1);	//float是单精度浮点数
	float t = atof(str1);	//double 是双精度浮点数，此处stof返回的是double型的，强制转换成float会损失精度，所以有warning

}