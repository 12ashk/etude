#include<stdio.h>

#define N 10

struct date
{
  int y;
  int m;
  int d;
};

int main(void)
{
  struct date date[N];
  struct date temp;
  int i, j;

  for(i = 0; i < N; i++)
    {
      scanf("%d %d %d", &date[i].y, &date[i].m, &date[i].d);
    }

  for(i = N; i > -1; i--)
    {
      for(j = (i + 1); j < N; j++)
	{
	  if(10000*date[j-1].y+100*date[j-1].m+date[j-1].d
	     > 10000*date[j].y+100*date[j].m+date[j].d)
	    {
	      temp = date[j-1];
	      date[j-1] = date[j];
	      date[j] = temp;
	    }
	}
    }
  
  printf("\n");

  for(i = 0; i < N; i++)
    {
      printf("%d %d %d\n", date[i].y, date[i].m, date[i].d);
    }

  return 0;
}
