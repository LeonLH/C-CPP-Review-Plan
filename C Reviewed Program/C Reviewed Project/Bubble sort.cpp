#include<iostream>
#include<stdlib.h>
using namespace std;

void BubbleSort(int *p )
{
	
}

void TestBubbleSort()
{
	int a[10]={12,345,567,89,9,45,98,78,42,23};
	int i = 0,j = 0,t = 0;

	while(j<9)	//�˴�jѭ��9�Σ�ѡ��9����Сֵ�Դ�ð�ݵ����棬���һ�β��ñȽ�
	{
		i = 9;	
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
	i =0 ;
	while(i<10)
	{
		cout << a[i] <<endl;
		++i;
	}
	system("pause");

	
//	BubbleSort(a);
}
