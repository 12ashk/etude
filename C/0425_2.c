#include<stdio.h>

int main(void)
{
	float a,b,c;
	char d;

	printf("plsease enter the expression\n");
	scanf("%f",&a);
	scanf(" %c",&d);
	
	if(d == '+')
	{
		scanf("%f",&b);
		c = a + b;
		printf("=%f\n",c);
	}
	else if(d == '-')
	{
		scanf("%f",&b);
		c = a - b;
		printf("=%f\n",c);
	}
	else if(d == '/')
	{
		scanf("%f",&b);
		c = a / b;
		printf("= %f\n",c);
	}
	else if(d == '*')
	{
		scanf("%f",&b);
		c = a * b;
		printf("= %f\n",c);
	}
	else
	{
		printf("error\n");
	}

	return 0;
}
