#include <stdio.h>
int main()
{
	float n1,n2,res;
	char ch;
	printf("Enter number 1:\n");
	scanf("%f", &n1);
	printf("Enter number 2\n");
	scanf("%f", &n2);
	printf("Choose a mathematical operation:\n");
	scanf("%c", &ch);
	res=0;
	switch(ch)
	{
		case'+':
			res=n1+n2;
			break;
			case'-':
				res=n1-n2;
				break;
				case'*':
					res=n1*n2;
					break;
					case'/':
						res=n1/n2;
						break;
						default:
							printf("Please select an operation from the menu");
						}
						printf("REsult:%f %c %f=%f\n", n1,ch,n2,res);
						return 0;
					}
