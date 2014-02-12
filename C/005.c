#include<stdio.h>

int main(void)
{
	int i,total = 0;

	i = 1;

	while(i <= 10)
	{
		total += i;
		i++;
	}

	printf("total = %d\n",total);

	return 0;
}
