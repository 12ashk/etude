#include<stdio.h>

int fizzbuzz(int i);

int A[15] = {0, 0, 1, 0, 2, 1, 0, 0, 1, 2, 0, 1, 0, 0, 3};

int main(void)
{
	int num;
	printf("input number: ");
	scanf("%d", &num);
	fizzbuzz(num);
	printf("\n");
	return 0;
}

int fizzbuzz(int i)
{
	int t;
	if(i == 0){
		return 0;
	}
	else{
		t = fizzbuzz(i-1);
		if(A[t] == 0){
			printf(" %d", i);
			return t+1;
		}
		else if(A[t] == 1){
			printf(" Fizz");
			return t+1;
		}
		else if(A[t] == 2){
			printf(" Buzz");
			return t+1;
		}
		else{
			printf(" FizzBuzz\n");
			return 0;
		}
	}
}
