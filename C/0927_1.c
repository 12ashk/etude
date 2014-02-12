/* 3x3 matrix determinant */
#include<stdio.h>
#define N 3

int main(void)
{
	int i, j, det, a[N][N];
	
	printf("input 3x3 matrix: \n");
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			scanf("%d", &a[i][j]);
		}
	}

	det = (a[0][0] * (a[1][1]*a[2][2] - a[1][2]*a[2][1])
		   - a[0][1] * (a[1][0]*a[2][2] - a[1][2]*a[2][0])
		   + a[0][2] * (a[1][0]*a[2][1] - a[1][1]*a[1][1]*a[2][0]));

	printf("%d\n", det);

	return 0;
}
