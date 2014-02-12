#include<stdio.h>
#include<stdlib.h>

struct node
{
	int key;
	struct node *next;
	struct node *prev;
}*head, *tail;

void printlist(void);
void listinitialize(void);
struct node *insertafter(int v, struct node *p);
void sort(void);
void exchange(struct node *p, struct node *q);

void sort(void)
{
	struct node *x, *y;
	for(x = tail; x->prev->prev != NULL; x = x->prev){
		for(y = head->next; y->next->next != NULL; y = y->next){
			if(y->key > y->next->key){
				exchange(y, y->next);
			}
		}
	}
}

void printlist(void)
{
	struct node *x;
	struct node *temp;
	int count, i;
	x = head->next;
	if(x->key == x->next->key){
		count = 1;
		temp->key = x->key;
		for(x = x->next; temp->key == x->key; x = x->next){
			count++;
		}
		printf(" %d^%d", temp->key, count);
	}
	else{
		printf(" %d", x->key);
		x = x->next;
	}
	while(x->next != NULL){
		if(x->key == x->next->key){
			count = 1;
			temp->key = x->key;
			for(x = x->next; temp->key == x->key; x = x->next){
				count++;
			}
			printf(" * %d^%d", temp->key, count);
		}
		else{
			printf(" * %d", x->key);
			x = x->next;
		}
	}
	printf("\n");
}

void listinitialize(void)
{
	head = (struct node*) malloc(sizeof(*head));
	tail = (struct node*) malloc(sizeof(*tail));
	head->next = tail;
	tail->next = NULL;
	tail->prev = head;
	head->prev = NULL;
}

struct node *insertafter(int v, struct node *p)
{
	struct node *x;
	x = (struct node *)malloc(sizeof(*x));
	x->key = v;
	x->next = p->next;
	p->next->prev = x;
	x->prev = p;
	p->next = x;

	return x;
}

void exchange(struct node *p, struct node *q)
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(*temp));
	temp->key = p->key;
	p->key = q->key;
	q->key = temp->key;
}
