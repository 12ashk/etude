#include<stdio.h>

int main(void)
{
	int i, a;

	scanf("%d",&a);

	for(i = 1; i < a; i++)
	{
		if((i % a) == 0)
		{
			break;
		
		}
	}

	if(i == a)
	{
		printf("%d is prime\n", a);
	}
	else
	{
		printf("%d is not prime\n", a);
	}

	return 0;
}
