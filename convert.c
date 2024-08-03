#include <stdio.h>
int any_to_decimal(int n,int b1);
int decimal_to_any(int n,int b2);
int main()
{
	int b1,b2,num;
	do
	{
		printf("Enter the base to convert from(between 2 and 10):");
		scanf("%d",&b1);
	}
	while(b1<2||b1>10);
	do
	{
		printf("Enter the base to convert to(between 2 and 10):");
		scanf("%d",&b2);
	}
	while(b2<2||b2>10||b2==b1);
	do
	{
		printf("enter non negative number in base %d :",b1);
		scanf("%d",num);
	}
	while(num<0);
	int decimal;
	decimal=any_to_decimal(num,b1);
	if(decimal==-1)
	{
		printf("Please enter the number within base");
		return -1;
	}
	int result=decimal_to_any(decimal,b2);
	printf("Number after conversion: %d\n",result);
	return 0;

	int any_to_decimal(int n,int b1)
	{
		int res=0;
		if(n==0)
		return res;
		int dig=n%10;
		if(dig>=b1)
		return -1;
		res+=dig;
		res*=b1;
		return any_to_decimal(n/10,b1);
	}
	int decimal_to_any(int n,int b2)
	{
		int r=0;
		if(n==0)
		return r;
		int dig=n%b2;
		r+=dig;
		return decimal_to_any(n/b2,b2);
	}
