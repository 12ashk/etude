#include<stdio.h>
#define M 5
#define N 3
#define L 4

int main(void)
{
  int i, j, k, l;
  int a[M][L], b[L][N];

  printf("A (%dx%d)?\n", M, L);
  for(i = 0; i < M; i++)
    {
      for(j = 0;j < L; j++)
	{
	  scanf("%d", &a[i][j]);
	}
    }

  printf("B (%dx%d)?\n", L, N);
  for(i = 0; i < L; i++)
    {
      for(j = 0; j < N; j++)
	{
	  scanf("%d", &b[i][j]);
	}
    }

  printf("AB =\n");
  for(i = 0; i < M; i++)
    {      
      for(j = 0, l = 0; j < N; j++, l = 0)
	{
	  for(k = 0; k < L; k++)
	    {
	      l += a[i][k] * b[k][j];
	    }
	  printf("%5d", l);
	}
      printf("\n");
    }

  return 0;
}
