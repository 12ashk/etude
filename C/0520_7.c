#include<stdio.h>

extern int inpint(void);
extern float impdbl(void);

int main(void)
{
  int n;

  scanf("%d",&n);
  
  switch(n)
    {
    case 0:printf("integer:%d\n",inpint());
           break;

    case 1:printf("float point:%f\n",impdbl());
           break;
    default: break;
    }

   return 1;
}

#include<stdio.h>

int inpint(void)
{
  int n;

  scanf("%d",&n);1

  return n;
}


#include<stdio.h>

float impdbl(void)
{
  float n;

  scanf("%f",&n);

  return n;
}
