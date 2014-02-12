#include<stdio.h>

void make_table(int num);

int main(void)
{
	int num;
	printf("input number: ");
	scanf("%d", &num);
	make_table(num);
	printf("\n");
	return 0;
}

void make_table(int num)
{
	int A[15] = {0};
	A[2] = 1;
	A[4] = 2;
	A[5] = 1;
	A[8] = 1;
	A[9] = 2;
	A[11] = 1;
	A[14] = 3;
	int i, j;
	
	for(i = 1, j = 0; i <= num; i++){
		if(A[j] == 0){
			printf(" %d", i);
			j++;
		}
		else if(A[j] == 1){
			printf(" Fizz");
			j++;
		}
		else if(A[j] == 2){
			printf(" Buzz");
			j++;
		}
		else{
			printf(" FizzBuzz");
			j = 0;
		}
	}
}
