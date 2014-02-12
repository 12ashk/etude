#include<stdio.h>

void exchange(void);

int main(void)
{
	exchange();

	return 0;
}

void exchange(void)
{
	int x, y, z;

	printf("please input data: x = ");
	scanf("%d", &x);
	printf("please input data: y = ");
	scanf("%d", &y);

	if(x > y)
	{
		z = x;
		x = y;
		y = z;
	}

	printf("x = %d, y = %d\n", x, y);
}
