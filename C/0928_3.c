/* determinant */
#include<stdio.h>

int main(void)
{
	int i, j, k, N;
	double det = 1, buf;
	printf("input matrix size: ");
	scanf("%d", &N);

	double a[N][N];

	printf("input matrix:\n");
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			scanf("%lf", &a[i][j]);
		}
	}

	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			if(i < j){
				buf = (a[j][i] / a[i][i]);
				for(k = 0; k < N; k++){
					a[j][k] -= a[i][k] * buf;
				}
			}
		}
	}

	for(i = 0; i < N; i++){
		det *= a[i][i];
	}

	printf("%f\n", det);

	return 0;
}
