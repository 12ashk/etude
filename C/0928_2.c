/*linear search*/
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

int search(key)
{
	int i;
	for(i = 0; i < n; i++){
		if(table[i].key == key){
			printf("%d\n", table[i].data);
			return 0;
		}
	}
	return -1;
}
