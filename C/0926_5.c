/*N by N matrix determinant abandon */

#include<stdio.h>
#define N 3

int main(void)
{
	int i, j;
	int a[N][N];

	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			scanf("%d", &a[i][j]);
		}
	}


