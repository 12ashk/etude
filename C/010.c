#include<stdio.h>

int main(void)
{
	int i;

	scanf("%d", &i);

	if(i % 400 == 0 || (i % 4 == 0 && i % 100 != 0))
	{
		printf("%d is a leap year\n", i);
	}
	else
	{
		printf("%d is not a leap year\n", i);
	}

	return 0;
}
