#include<stdio.h>

int plusint(int a, int b)
{
	return a + b;
}

void main()
{
	int i1, i2;
	int total;

	scanf("%d %d", &i1, &i2);

	total = plusint(i1, i2);

	printf("%d\n", total);
}
