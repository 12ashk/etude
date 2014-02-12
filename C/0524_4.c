#include <stdio.h>

void prt(char (*sp)[7], int n);
void wprt(char (*sp)[7], int n);

int main (void)
{
  char str[3][7] = {"japan", "usa", "france"};

  prt(str, 3);
  wprt(str, 3);

  return 0;
}

void prt(char (*sp)[7], int n)
{
  int i;

  for(i = 0; i < n; i++, sp++)
    {
      printf("%d,%s,", i, sp);
    }
  printf("\n");
}

void wprt(char (*sp)[7], int n)
{
  int i, j;

  for(i = j = 0; i < n; i++, sp++, j = 0)
    {
      printf("%d,",i);
      for(; *((*sp) + j) != '\0'; j++)
	{
	  printf("%c", *((*sp) + j));
	}
      printf("\n");
    }
}
