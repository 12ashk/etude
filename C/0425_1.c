#include<stdio.h>

int main(void)
{
	float a, b, c;
	
	printf("plsease enter the triangle's side\n");
	scanf("%f", &a);
	scanf("%f", &b);
	scanf("%f", &c);

	if(a > 0 && b > 0 && c > 0)
	{
		if(a < b + c && a > b && a > c)
		{
			printf("OK\n");
		}
		else if(b < a + c && b > a && b > c)
		{
			printf("OK\n");
		}
		else if(c < a + b && c > a && c > b)
		{
			printf("OK\n");
		}
		else
		{
			printf("NG\n");
		}
	}
	else
	{
		printf("NG\n");
	}

	return 0;
}
