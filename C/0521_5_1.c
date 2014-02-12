#include<stdio.h>

int main(void)
{
  char moji[7] = "spring";
  int i = 0;

  for(; moji[i] != '\0'; i++)
    {
      printf("%c", moji[i]);
    }

  printf("\n");

  return 0;
}
