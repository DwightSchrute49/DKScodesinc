#include<stdio.h>
int main()
{
	int n100, n50, n10, n5, n2, n1, num;
	
	printf("\nEnter the amount : ");
	scanf("%d", &num);
	
	//Numbers of notes of 100
	n100 = num / 100;	
	num = num % 100;
	
	//Numbers of notes of 50
	n50 = num / 50;
	num = num % 50;
	
	//Numbers of notes of 10
	n10 = num / 10;
	num = num % 10;
	
	//Numbers of notes of 5
	n5 = num / 5;
	num = num % 5;
	
	//Numbers of notes of 2
	n2 = num / 2;
	num = num % 2;
	
	//Numbers of notes of 1
	n1 = num / 1;
	
	printf("\n\nTo give amount of %d you have to give : \n");
	printf("%d of notes of hundred.\n", n100);
	printf("%d of notes of fifty.\n", n50);
	printf("%d of notes of ten.\n", n10);
	printf("%d of notes of five.\n", n5);
	printf("%d of notes of two.\n", n2);
	printf("%d of notes of one.\n", n1);
	
	return 0;
}


