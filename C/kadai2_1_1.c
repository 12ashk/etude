#include<stdio.h>

int main(void)
{
	int i, j;
	char a[1000];

	scanf("%s", a);

	for(i = 0, j = 0; a[i] != '\0'; i++)
	{
		if(a[i] == 'c' || a[i] == 'g')
		{
			j++;
		}
	}

	printf("GC content = %f%%\n",(float) j/i * 100);

	return 0;
}
