#include<stdio.h>

int main(void)
{
	int a,b,c;

	a = 12;
	b = 5;

	c = getchar();

	if (c == '+')
	{
		printf("a + b = %d\n",a + b);
	}
	else if (c == '-')
	{
		printf("a - b = %d\n",a -b);
	}
	else
	{
		printf("Bad character !!\n");
	}

	return 0;
}
