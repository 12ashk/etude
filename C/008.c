#include<stdio.h>

int main(void)
{
	int i, c;

	for(i = 1; ; i++)
	{
		scanf("%d", &c);

		if(c == (-1))
		{
			break;
		}
		else if(c <= 32 || c >= 127)
		{
			continue;
		}
		else
		{
			printf("%d : %x = %c\n", i, c, c);
		}
	}

	return 0;
}
