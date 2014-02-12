#include<stdio.h>
#define NUM 600851475143

int main(void)
{
	int table[100] = {0};
	long int i;
	int j;
	if(NUM % 2 == 0){
		table[0] = 2;
	}

	for(i = 3, j = 0; i < NUM/2; i += 2){
		if(NUM % i == 0){
			table[j] = i;
			j++;
		}
		if(table[j] * i > NUM){
			break;
		}
	}

	for(j = 0; table[j] != 0; j++){
	}
	printf("%d\n", table[j-1]);

	return 0;
}
