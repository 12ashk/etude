/*linked list*/
#include<stdio.h>
#include<stdlib.h>
#define N 32767

struct node
{
	int key;
	struct node *next;
}*head, *tail;

void listinitialize(void);
struct node *insertafter(int v, struct node *p);
void merge_sort(struct node *p, struct node *q);
struct node *lastlist(void);

int main(void)
{
	int i, j, num, key;
	printf("input number of data: ");
	scanf("%d", &num);
	printf("input key: ");
	scanf("%d", &key);
	struct node *x;
	listinitialize();
	for(i = 0; i < num; i++){
		printf("input key: ");
		scanf("%d", &key);
		x = insertafter(key, x);
	}

	for(i = 1; ; i *= 2){
		if(i == num){
			break;
		}
		if(num < i){
			lastlist();
			for(j = num; j < i; j++){
				x = insertafter(N, x);
			}
			break;
		}
	}

	return 0;
}

void listinitialize(void)
{
	head = (struct node*) malloc(sizeof(*head));
	tail = (struct node*) malloc(sizeof(*tail));
	head->next = tail;
	tail->next = NULL;
}

struct node *insertafter(int v, struct node *p)
{
	struct node *x;
	x = (struct node *)malloc(sizeof(*x));
	x->key = v;
	x->next = p->next;
	p->next = x;

	return x;
}

void deletenext(struct node *p)
{
	struct node *x;
	x = p->next;
	p->next = p->next->next;
	free(x);
}

struct node *lastlist(void)
{
	struct node *x;
	x = (struct node *)malloc(sizeof(*x));
	x = head;
	while(1){
		if(x->next->next == NULL){
			break;
		}
			x = x->next;
	}

	return x;
}
