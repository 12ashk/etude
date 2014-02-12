#include<stdio.h>

int kuku[99][99];

void table(void);
void hyoji(void);

int main(void)
{
  table();
  hyoji();

  return 0;
}

void table(void)
{
  int i, j;

  for(i = 0; i < 9; i++)
    {
      for(j = 0; j < 9; j++)
	{
	  kuku[i][j] = (i + 1) * (j + 1);
	}
    }
}

void hyoji(void)
{
  int i, j;

  for(i = 0; i < 9; i++)
    {
      for(j = 0; j < 9; j++)
	{
	  printf("%5d",kuku[i][j]);
	}

      printf("\n");
    }
}
