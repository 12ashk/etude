#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
  float x,y;
  register float n, m;

  n=1;

  srand(time(NULL));
  
  for(m=1; m < 10000000; m++)
    {
      x =rand() / (float)RAND_MAX;
      y =rand() / (float)RAND_MAX;

      if(x*x + y*y  < 1)
	{
	  n = n+1;
	}
    }

  printf("%f\n",4*n/m);

}
