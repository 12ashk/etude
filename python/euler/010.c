#include<stdio.h>
#define N 100000

long long int sum_prime(int n)
{
	long long int count = 2;
	int lst[N];
	int i, j;

	for(i = 0; i < n; i++){
		lst[i] = 1;
	}
	for(i = 3; i < n; i+=2){
		if(lst[i]){
			count += i;
			for(j = i*2; j < n; j+=i){
				lst[j] = 0;
			}
		}
	}
	return count;
}

int main(void)
{
	printf("%lld\n", sum_prime(2000000));

	return 0;
}
