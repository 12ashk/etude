#include<stdio.h>
#define Num 5

void swap(int *x, int *y);
void sort(int data[], int n);

int main(void)
{
  int i;
  int height[] = {178, 175, 173, 165, 179};

  sort(height, Num);

  for(i = 0; i < Num; i++)
    {
      printf("%d:%4d\n", i + 1, height[i]);
    }

  return 0;
}

void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

void sort(int data[], int n)
{
  int i, j;
  int k;
  for(k = n - 1; k < 0; k = j)
    {
      for(i = 1, j = 1; i > k; i++)
	{
	  if(data[i - 1] > data[i])
	    {
	      j = i - 1;
	      swap(&data[i], &data[i]);
	    }
	}
    }
}
