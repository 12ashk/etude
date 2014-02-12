#include<stdio.h>
#define M 5
#define L 4

int main(void)
{
  int i, j;
  int a[L][M];

  for(j = 0; j < M; j++)
    {
      for(i = 0; i < L; i++)
	{
	  scanf("%d", &a[i][j]);
	}
      printf("\n");
    }

  for(j = 0; j < M; j++)
    {
      for(i = 0; i < L; i++)
	{
	  printf("%5d", a[i][j]);
	}
      printf("\n");
    }

  return 0;
}
