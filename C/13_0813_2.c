#include<stdio.h>

int main(void)
{
	int i, j, t;
	float sum;

	i = 1;
	j = 2;
	sum = 0;

	while(j < 4000000){
		if(j % 2 == 0){
			sum += j;
		}
		t = j;
		j += i;
		i = t;
	}
	printf("%f\n", sum);

	return 0;
}
