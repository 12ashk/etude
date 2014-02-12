#include<stdio.h>

struct gstudent
{
  char  name[20];
  int   height;
  float weight;
  long  shols;
};

void hiroko(struct gstudent *std);

int main(void)
{
  struct gstudent sanaka = {"sanaka", 175, 90, 70000};

  hiroko(&sanaka);

  printf("height = %d\n", sanaka.height);
  printf("weight = %.1f\n", sanaka.weight);

  return 0;
}

void hiroko(struct gstudent *std)
{
  if((*std).height < 180)
    {
      (*std).height = 180;
    }
  if((*std).weight > 80)
    {
      std->weight = 80;
    }
}

