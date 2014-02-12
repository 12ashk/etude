#include<stdio.h>
#include<stdlib.h>

struct node
{
	int key;
	struct node *next;
	struct node *prev;
}*head;

void printlist(void);
void listinitialize(void);
struct node *insertafter(int v, struct node *p);

void printlist(void)
{
	struct node *x;
	x = head->next;
	while(x != NULL){
		printf("%4d ", x->key);
		x = x->next;
	}
	printf("\n");
}

void listinitialize(void)
{
	head = (struct node *)malloc(sizeof(*head));
	head->next = NULL;
	head->prev = NULL;
}

struct node *insertafter(int v, struct node *p)
{
	struct node *x;
	x = (struct node *)malloc(sizeof(*x));
	x->key = v;
	x->next = NULL;
	x->prev = p;
	p->next = x;

	return x;
}
