#include<stdio.h>

int cond(int x);

int main(void)
{
	int x;
	int ret;

	printf("please input data: x =");
	scanf("%d", &x);

	ret =cond(x);

	printf("ret = %d\n", ret);

	return 0;
}

int cond(int x)
{
	if(x >= 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
