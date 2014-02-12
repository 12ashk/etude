#include<stdio.h>

int main (void)
{
  int j, i;
  char season[4][7] = {"spring", "summer", "autumn", "winter"};

  for(i = 0; i < 4; i++)
    {
      for(j = 0; j < 6; j++)
	{
	  printf("%c", season[i][j]);
	}
      printf(" ");
    }
  printf("\n");

  return 0;
}
