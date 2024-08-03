#include <stdio.h>
int main(){
	double dep,pp,yrs;
	printf("Annual depreceiation:");
	scanf("%lf",&dep);
	printf("Years of service:");
	scanf("%lf", &yrs);
	printf("Purchase price:");
	scanf("%lf", &pp);
	dep*=yrs;
	pp-=dep;
	printf("Salvage Value: %.2lf\n", pp);
	return 0;
}
