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
	double f = atof(str1);	//float�ǵ����ȸ�����
	float t = atof(str1);	//double ��˫���ȸ��������˴�stof���ص���double�͵ģ�ǿ��ת����float����ʧ���ȣ�������warning

}