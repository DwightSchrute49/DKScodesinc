#include <stdio.h>
#include <math.h>
void main(){
	float number= 34.5678;
	float num;
	printf("int is %d\n", (int)number);
	num=roundf(number*100)/100;
	printf("rounded to 2 dec is %2f",num);
}
