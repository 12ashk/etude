#include<stdio.h>

int main(void)
{
	float a,b,c;
	char d;

	printf("plsease enter the expression\n");
	scanf("%f",&a);
	scanf(" %c",&d);
	
	switch(d)
	{
		case '+':
			scanf("%f",&b);
			c = a + b;
			printf("=%f\n",c);
			break;	

		case '-':
			scanf("%f",&b);
			c = a - b;
			printf("=%f\n",c);
			break;

		case'/':
			scanf("%f",&b);
			c = a / b;
			printf("= %f\n",c);
			break;

		case '*':
			scanf("%f",&b);
			c = a * b;
			printf("= %f\n",c);

		default:
			printf("error\n");
	}

	return 0;
}
