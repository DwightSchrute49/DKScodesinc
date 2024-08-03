#include <stdio.h>
int main(){
	double dep,pp,sal,yrs,pp1;
	printf("Annual depreceiation:");
	scanf("%d",&dep);
	printf("Years of service:");
	scanf("%d", &yrs);
	printf("Purchase price:");
	scanf("%d", &pp);
	pp1=(dep*yrs);
	sal=pp-pp1;
	printf("Salvage Value: %d\n", sal);
	return 0;
}
