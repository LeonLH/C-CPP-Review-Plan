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

	while(j<9)	//此处j循环9次，选出9个最小值以此冒泡到上面，最后一次不用比较
	{
		i = 9;	
		while(i>j)	//此处j=0时，i循环9次，比较九次可以选出一个最小值浮到上面
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
