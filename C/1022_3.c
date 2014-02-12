#include<stdio.h>
#define N 500

void prime(int x);

int a[2][N];

int main(void)
{
	int i, j, k, count, num, original;
	printf("input : ");
	scanf("%d", &num);
	if(num == 0 || num == 1){
		printf("%d = %d\n", num, num);
	}
	else{
		prime(num);
		original = num;
		printf("%d = ", num);
		for(i = 0; a[0][i] != 0; i++){
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
			for(j++; j < i; j++){
				if(a[1][j] == 1){
					printf(" * %d", a[0][j]);
				}
				else if(a[1][j] > 1){
					printf(" * %d^%d", a[0][j], a[1][j]);
				}
			}
		}
		printf("\n");
	}
	return 0;
}

void prime(int x)
{
	int i, j, f, n;
	a[0][0] = 2;
	for(i = 1, n = 3; i < N; i++){
		for(; n <= x; n += 2){
			for(j = 0, f = 0; a[0][j] != 0; j++){
				if(n % a[0][j] == 0){
					f = 1;
					break;
				}
			}
			if(f == 0){
				a[0][i] = n;
				n += 2;
				break;
			}
		}
		if(n > x){
			break;
		}
	}
}
