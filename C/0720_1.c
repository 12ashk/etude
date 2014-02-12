#include<stdio.h>

int main(void)
{
    int i, j, k, l, n, N;

    printf("input power\n"); 
    scanf("%d", &n);
    printf("N?\n");
    scanf("%d", &N);

    float A[N][N], B[N][N];
    float C[N][N];

    printf("input %d * %d matrix\n", N, N);
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            scanf("%f", &A[i][j]);
            B[i][j] = A[i][j];
        }
    }

    for(l = 0; l < n; l++){
        for(i = 0; i < N; i++){
            for(j = 0; j < N; j++){
                for(l = 0; l < N; l++){
                    C[i][j] += A[i][l] * B[l][j];
                }
            }
        }

        for(i = 0; i < N; i++){
            for(j = 0; j < N; j++){
                B[i][j] = C[i][j];
                C[i][j] = 0;
            }
        }
    }

    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            printf("%5.2f", B[i][j]);
        }
        printf("\n");
    }

    return 0;
}

