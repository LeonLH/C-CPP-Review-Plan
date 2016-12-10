#include<iostream>
#include<stdlib.h>
using namespace std;
void Print(int *p,int nLen)
{
	int i =0 ;
	while(i<nLen)
	{
		cout << p[i] <<endl;
		++i;
	}
}

void Sort1(int *a,int nLen )
{//������ð
	int i = 0,j = 0,t = 0;

	while(j<nLen-1)	//�˴�jѭ��9�Σ�ѡ��9����Сֵ�Դ�ð�ݵ����棬���һ�β��ñȽ�
	{
		i = nLen-1;	
		while(i>j)	//�˴�j=0ʱ��iѭ��9�Σ��ȽϾŴο���ѡ��һ����Сֵ��������
		{
			if(a[i]<a[i-1])
			{
				t = a[i];
				a[i] = a[i-1];
				a[i-1] = t;
			}
			--i;
		}
		++j;
	}
}

void Sort2(int *a,int nLen )
{//������ð
	int i = 0,j = 0,t = 0;

	while(j<nLen-1)	
	{
		i = nLen-1;
		while(i>j)	
		{
			if(a[i]>a[i-1])
			{
				t = a[i];
				a[i] = a[i-1];
				a[i-1] = t;
			}
			--i;
		}
		++j;
	}
}

void Sort3(int *a,int nLen )
{//������ð
	int i = 0,j = 0,t = 0;
	j = nLen-1;
	while(j>0)	
	{
		i = 0;
		while(i<j)	
		{
			if(a[i]>a[i+1])
			{
				t = a[i];
				a[i] = a[i+1];
				a[i+1] = t;
			}
			++i;
		}
		--j;
	}
}

void Sort4(int *a,int nLen )
{//������ð
	int i = 0,j = 0,t = 0;
	j = nLen-1;
	while(j>0)	
	{
		i = 0;
		while(i<j)	
		{
			if(a[i]<a[i+1])
			{
				t = a[i];
				a[i] = a[i+1];
				a[i+1] = t;
			}
			++i;
		}
		--j;
	}
}

void TestBubbleSort()
{
	int a[10]={12,345,567,89,9,45,98,78,42,23};
	Sort1(a,_countof(a));
	Print(a,_countof(a));
	cout << endl;
	Sort2(a,_countof(a));
	Print(a,_countof(a));
	cout << endl;
	Sort3(a,_countof(a));
	Print(a,_countof(a));
	cout << endl;
	Sort4(a,_countof(a));
	Print(a,_countof(a));
	cout << endl;

	system("pause");

	
//	BubbleSort(a);
}
