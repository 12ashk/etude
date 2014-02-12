#include<stdio.h>

int main(void)
{
	int i;
	double d, t = 0.0, h;

	for(i = 1; i <= 3; i++)
	{
		scanf("%lf", &d);
		t +=d;
	}

	h = t / 3;

	printf("%.2f\n", h);

	return 0;
}
