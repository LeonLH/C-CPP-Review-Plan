#include<stdio.h>
#include<stdlib.h>

int GCD(int i ,int j ){
//Greatest Common Divisor ��ٷ�
	int k=1,min,max,res ;
	min = ((i<j)?i:j);
	max = ((i>j)?i:j);

	while(k<=min){
		if(min%k==0 && max%k==0)
			res = k;
		++k;
	}
	return res ;//�������1
}

int GCD1(int i ,int j ){
//Greatest Common Divisor շת�����
	int k=0,min,max,res ;
	min = ((i<j)?i:j);
	max = ((i>j)?i:j);
	while(1){	
		k = max%min;
		if(k==0){
			res = min;
			break;
		}
		max = min;
		min = k;
	}
	return res ;//�������1
}
int LCM(int i ,int j){
//Lowest Common Multiple
	int res,gcd ;
	gcd = GCD(i,j);
	res = (i/gcd)*(j/gcd)*gcd;
	return res ;
}

void TestGCD(){
	int i;
	int j;
	int k,h;
	puts("�����������������Կո����");
	scanf("%d %d",&i,&j);
	k=GCD1(i,j);
	printf("%d��%d�����Լ����%d\n",i,j,k);
	h = LCM(i,j);
	printf("%d��%d����С��������%d\n",i,j,h);
	system("pause");


}
void TestLCM(){

}