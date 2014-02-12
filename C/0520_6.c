#include<stdio.h>

void prn1(void);
void prn2(void);
static void spc(int n);

int main(void)
{
  printf("Tyokyo");
  spc(5);
  prn1();

  return 0;
}

void prn1(void)
{
  printf("New york");
  spc(7);
  prn2();
}

void prn2(void)
{
  printf("Paris");
  spc(3);
  printf("London\n");
}

static void spc(int n)
{
  int i;

  for(i = 0; i < n; i++)
    {
      printf(" ");
    }
}
