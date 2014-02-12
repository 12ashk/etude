#include<stdio.h>
#define N 3

int cofactor(int x);

int *p, pc, det, count = N;

int main(void)
{
	int i, j;
	int a[N * N];

	for(i = 0; i < (3 * N); i++){
		scanf("%d", &a[i]);
	}
	p = a;
	det = a[i - 1];
	pc = (3 * N - 1);

	printf("%d\n", cofactor());

	return 0;
}

int cofactor(int x)
{
	int i;
	int t;

	if(count == 1){
		return det;
	}
	else{
		count--;
		pc -= (N + 1);
		return (*(p + pc) * cofactor(det));
	}
}
