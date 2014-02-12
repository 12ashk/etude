#include<stdio.h>
#define M 5
#define N 3
#define L 4

int main(void)
{
  int i, j, l, k;
  int a[L][M], b[N][L], c[N][M];

  for(j = 0; j < M; j++)
    {
      for(i = 0; i < L; i++)
	{
	  scanf("%d", &a[i][j]);
	}
    }

  for(j = 0; j < L; j++)
    {
      for(i = 0; i < N; i++)
	{
	  scanf("%d", &b[i][j]);
	}
    }


  for(j = 0; j < M; j++)
    {      
      for(i = 0, l =0; i < N; i++)
	{
	  for(k = 0; k < L; k++)
	    {
	      printf("%d,%d\n",a[k][j], b[i][k]);
	      l = l + a[k][j] * b[i][k];
	    }
      c[i][j] = l;
      l = 0;
	}
    }

  for(j = 0; j < M; j++)
    {
      for(i = 0; i < N; i++)
	{
	  printf("%5d", c[i][j]);
	}
      printf("\n");
    }

  return 0;
}
