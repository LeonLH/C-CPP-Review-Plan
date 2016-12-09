#include<stdio.h>
#include<stdlib.h>

int GCD(int i ,int j ){
//Greatest Common Divisor 穷举法
	int k=1,min,max,res ;
	min = ((i<j)?i:j);
	max = ((i>j)?i:j);

	while(k<=min){
		if(min%k==0 && max%k==0)
			res = k;
		++k;
	}
	return res ;//如果返回1
}

int GCD1(int i ,int j ){
//Greatest Common Divisor 辗转相除法
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
	return res ;//如果返回1
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
	puts("请输入两个整数，以空格隔开");
	scanf("%d %d",&i,&j);
	k=GCD1(i,j);
	printf("%d和%d的最大公约数是%d\n",i,j,k);
	h = LCM(i,j);
	printf("%d和%d的最小公倍数是%d\n",i,j,h);
	system("pause");


}
void TestLCM(){

}