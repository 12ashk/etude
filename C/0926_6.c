/*bucket sort program */
#include<stdio.h>

int main(void)
{
	int num, max, i, j;

	printf("input max number: ");
	scanf("%d", &max);
	printf("input number of array: ");
	scanf("%d", &num);
	int a[num];
	printf("input array:\n");
	for(i = 0; i < num; i++){
		scanf("%d", &a[i]);
	}
	
	int temp[max];
	for(i = 0; i < max; i++){
		temp[i] = 0;
	}

	for(i = 0; i < num; i++){
	   temp[a[i]]++; 
	}
	
	for(i = 0; i < max; i++){
		for(j = 1; j <= temp[i]; j++){
			printf("%d ", i);
		}
	}
	printf("\n");

	return 0;
}
