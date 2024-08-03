#include <stdio.h>
int main()
{
	int r,i,j,sp;
	printf("Enter rows:");
	scanf("%d",&r);
	for(i=0;i<r;i++)
	{
		for(sp=0;sp<r-i-1;sp++)
		{
			printf(" ");
		}
		for(j=0;j<2*i+1;j++)
		{
			if(j==0||j==2*i)
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	for(i=r-2;i>=0;i--)
	{
		for(sp=0;sp<r-i-1;sp++)
		{
			printf(" ");
		}
		for(j=0;j<2*i+1;j++)
		{
			if(j==0||j==2*i)
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}
