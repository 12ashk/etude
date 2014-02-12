#include<stdio.h>

int main(void)
{
	int i, j, k;

	for(i = 1; i < 1000; i++){
		for(j = i; j < 1000; j++){
			k = 1000 - i - j;
			if((i+j+k==1000) && (i*i+j*j == k*k)){
				printf("%d\n", i*j*k);
				return 0;
			}
		}
	}
	return 0;
}
