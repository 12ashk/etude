#include<stdio.h>
#define N 2147483
#define M 2147483647

void prime(int x);

int a[2][N];

int main(void)
{
	int i, j, k, count, num, original;
	printf("input : ");
	scanf("%d", &num);
	prime(num);
	original = num;

	for(i = 0; i < 10; i++){
		printf("%d ", a[0][i]);
	}
	printf("%d = ", num);
	for(i = 0; a[0][i] != M; i++){
		count = 0;
		if(num % a[0][i] == 0){
			count = 1;
			num /= a[0][i];
			a[1][i] = count;
			while(1){
				if(num % a[0][i] != 0){
					break;
				}
				count++;
				num /= a[0][i];
				a[1][i] = count;
			}
		}
	}

	for(j = 0; j < i; j++){
		if(a[1][j] == 1){
			printf("%d", a[0][j]);
			break;
		}
		else if(a[1][j] > 1){
			printf("%d^%d", a[0][j], a[1][j]);
			break;
		}
	}
	if(j == i){
		printf("%d", original);
	}
	else{
		for(j++ ; j < i; j++){
			if(a[1][j] == 1){
				printf(" * %d", a[0][j]);
			}
			else if(a[1][j] > 1){
				printf(" * %d^%d", a[0][j], a[1][j]);
			}
		}
	}
	printf("\n");

	return 0;
}

void prime(int x)
{
	int i, j, f, n;
	a[0][0] = 2;
	for(i = 1, n = 3; n < x; i++){
		printf("a ");
		for(; n <= x/2; n++){
			printf("b ");
			for(j = 2, f = 0; j <= n/2; j++){
				printf("c ");
				if(n % j == 0){
					f = 1;
					printf("f ");
					break;
				}
			}
			if(f == 0){
				printf("n ");
				a[0][i] = n;
				n++;
				break;
			}
		}
		if(n > x/2){
			printf("m ");
			i++;
			a[0][i] = M;
			break;
		}
	}
}
