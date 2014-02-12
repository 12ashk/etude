#include<stdio.h>

int main(void)
{
	int i, total = 0;

	i = 1;

	do
	{
		total += i;
		i++;
	}while(i <= 10);

	printf("total = %d\n", total);

	return 0;
}
	
