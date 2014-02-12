#include<stdio.h>

int main(void)
{
  int i;
  char season[][7] = {"spring", "summer", "autumn", "winter"};

  for(i = 0; i < 4; i++)
    {
      printf("%s    ", season[i]);
    }

  printf("\n");

  return 0;
}
