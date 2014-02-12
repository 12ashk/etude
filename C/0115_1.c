#include<stdio.h>

void fizzbuzz(int i);

int main(void)
{
	int i;
	printf("input number: ");
	scanf("%d", &i);
	fizzbuzz(i);
	printf("\n");

	return 0;
}

void fizzbuzz(int i)
{
	if(i == 1){
		printf(" %d", i);
	}
	else{
		if(i % 3 == 0 && i % 5 == 0){
			fizzbuzz(i-1);
			printf(" FizzBuzz\n");
		}
		else if(i % 3 == 0){
			fizzbuzz(i-1);
			printf(" Fizz");
		}
		else if(i % 5 == 0){
			fizzbuzz(i-1);
			printf(" Buzz");
		}
		else{
			fizzbuzz(i-1);
			printf(" %d", i);
		}
	}
}
