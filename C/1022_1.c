#include<stdio.h>
#define N 1000000

void prime(int x);

int a[N];

int main(void)
{
	int i, count;
	int num, original;
	printf("input : ");
	scanf("%d", &num);

	prime(num);
	original = num;
	for(i = 0; i < 10; i++){
		printf("%d ", a[i]);
	}

	printf("%d = ", num);
	for(i = 0; a[i] <= original/2; i++){
		count = 0;
		if(num % a[i] == 0){
			count = 1;
			num /= a[i];
			while(1){
				if(num % a[i] != 0){
					break;
				}
				count++;
				num /= a[i];
			}
			if(count == 1){
				printf("%d", a[i]);
			}
			else{
				printf("%d^%d", a[i], count);
			}
			printf(" * ");
		}
	}

	if(num == original){
		printf("%d", original);
	}
	printf("\n");

	return 0;
}

void prime(int x)
{
	int i, j, f, n;
	a[0] = 2;
	for(i = 1, n = 3; n <= x; i++){
		for( ; n <= x; n++){
			for(j = 2, f = 0; j <= n; j++){
				if(n % j == 0 && n != j){
					f = 1;
					break;
				}
			}
			if(f == 0){
				a[i] = n;
				n++;
				break;
			}
		}
	}
}
