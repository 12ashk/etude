#include<stdio.h>

int main(void)
{
	int a, b, c;

	a = 12;
	b = 5;

	c = getchar();

	switch(c)
	{
		case '+':
			printf("a + b = %d\n",a + b);
			break;
		case '-':
			printf("a - b = %d\n",a - b);
			break;
		default:
			printf("bad character!!\n");
			break;
	}

	return 0;
}
