#include<stdio.h>
#include<complex>
using namespace std;
bool IsPrimeNumb(int j)
{
	int i=0;
	i = 2;
	while (i<j)
	{
		if(j%i!=0)
			++i;
		else
			break;
	}
	if(i==j)
		return true;
	else
		return false;

}

bool IsPrimeNumb2(int j)
{
	int i=0;
	i = 2;
	while(i<(j/2))
	{
		if(j%i!=0)
			++i;
		else
			break;
	}
	if(i==(j/2))
		return true;
	else
		return false;

}

bool IsPrimeNumb3(int j)
{
	int i=0;
	i = 2;
	double x = sqrt(j);
	while(i<x)
	{
		if(j%i!=0)
			++i;
		else
			break;
	}
	if(i>x)
		return true;
	else
		return false;

}

void TestPrimeNumb()
{
	/*
	int i =0;
	scanf("%d",&i);
	if(IsPrimeNumb(i))
		puts("是素数！");
	else
	{
		puts("不是素数！");
	}
*/	

	int i =101;
	int j =0;
	while(i<=200)
	{
//		if(IsPrimeNumb(i))
		if(IsPrimeNumb3(i))
//		if(IsPrimeNumb2(i))
		{
			printf("%d ",i);
			++j;
		}
		++i;
	}
	printf("\n共有%d个素数",j);
	system("pause");
}