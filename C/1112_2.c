#include<stdio.h>

int main(void)
{
	int i, c, d;
	c = 0;
	d = 0;

	int a[7] = {0, 1, 4, 4, 5, 1, 15};
	int b[7] = {0, 1, 4, 4, 4, 1, 20};
	int x[10];

	for(i = 0; i < 10; i++){
		if((a[c] < b[d] && c < 5) || (d > 4)){
			x[i] = a[c];
			c++;
		}
		else{
			x[i] = b[d];
			d++;
		}
	}

	for(i = 0; i < 10; i++){
		printf("%d ", x[i]);
	}

	printf("\n");

	return 0;
}
