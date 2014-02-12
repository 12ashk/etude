/*binary search*/
#include<stdio.h>
#define N 100

struct dict{
	int key;
	int data;
} table[N];

int search(int key);

int n;

int main(void)
{
	int i, key;
	printf("input data size: ");
	scanf("%d", &n);
	if(n > N){
		printf("data size is too big\n");
	}
	else{
		printf("input key following ascending-order\n")
		for(i = 0; i < n; i++){
			printf("input key: ");
			scanf("%d", &table[i].key);
			printf("input data: ");
			scanf("%d", &table[i].data);
		}
		printf("input the key: ");
		scanf("%d", &key);	
		if(search(key) == -1){
			printf("not found\n");
		}
	}

	return 0;
}

int search(int key)
{
	int low, high, middle;

	for(low = 0, high = n - 1; low <= high;){
		middle = (low + high) / 2;
		if(key == table[middle].key){
			printf("%d was found\n", table[middle].data);
			return 0;
		}
		else if(key < table[middle].key){
			high = middle - 1;
		}
		else{
			low = middle + 1;
		}
	}
	return -1;
}
