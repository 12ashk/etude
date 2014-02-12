#include<stdio.h>

int main(void)
{
  int cont;

  do
    {
      int num, i;

      do
	{
	  printf("input:");
	  scanf("%d",&num);

	  if(num < 0)
	    {
	      printf("erro\n");
	    }
	}while(num < 0);

	    for(i =1; i <= num; i++)
	      {
		printf("*");
	      }
		printf("\nagain? :");
		scanf("%d", &cont);

    }while(cont == 0);

     return 0;
}
