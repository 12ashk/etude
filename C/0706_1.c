#include<stdio.h>

int x, y;

int A(int x, int y); //Acharmann function

int main(void)
{
	scanf("%d %d", &x, &y);
	printf("%d\n", A(x, y));

	return 0;
}

int A(int x, int y)
{
	if(x == 0)
	{
		return y + 1;
	}
	else
	{
		if(y == 0)
		{
			return A(x - 1, 1);
		}
		else
		{
			return A(x - 1, A(x, y - 1));
		}
	}
}

