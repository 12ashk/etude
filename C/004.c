#include<stdio.h>

int main(void)
{
	int i, total = 0;

	for(i = 1; i <= 10;  i++)
	{
		total += i;
	}

	printf("total = %d\n", total);

	return 0;
}
