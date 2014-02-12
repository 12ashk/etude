/* N by N matrix determinant miss */

#include<stdio.h>
#define N 3

int main(void)
{
	int i, j, pc, det;
	int a[N * N];
	int *p;

	for(i = 0; i < (N * N); i++){
		scanf("%d", &a[i]);
	}

	p = a;
	det = a[0];

	for(pc = (i - 1); pc > 0; pc -= (N + 1)){
		det *= *(p + pc);
	}

	printf("%d\n", det);

	return 0;
}
