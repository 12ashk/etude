/*linked list*/
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int key;
	struct node *next;
}*head, *tail;

void listinitialize(void);
struct node *insertafter(int v, struct node *p);
void deletenext(struct node *p);
void exchange(struct node *p, struct node *q);

int main(void)
{
	int i, j, num, key;
	printf("input number of data: ");
	scanf("%d", &num);
	printf("input key: ");
	scanf("%d", &key);
	struct node *x;
	listinitialize();
	x = insertafter(key, head);
	for(i = 0; i < (num-1); i++){
		printf("input key: ");
		scanf("%d", &key);
		x = insertafter(key, x);
	}

	x = head;
	while(x->next->next != NULL){
		x = x->next;
		printf("%d ", x->key);
	}

	printf("\n");
	for(i = 0; i < num; i++){
		for(x = head->next; x->next->next != NULL; x = x->next){
			if(x->key > x->next->key){
				exchange(x, x->next);
			}
		}
	}		
	x = head;
	while(x->next->next != NULL){
		x = x->next;
		printf("%d ", x->key);
	}
	printf("\n");

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

void exchange(struct node *p, struct node *q)
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(*temp));
	temp->key = p->key;
	p->key = q->key;
	q->key = temp->key;
	free(temp);
}
