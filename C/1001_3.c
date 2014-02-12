/*linked list*/
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int key;
	struct node *next;
}*head, *tail;

int num;

void printlist(void);
void listinitialize(void);
struct node *insertafter(int v, struct node *p);
void deletenext(struct node *p);
void exchange(struct node *p, struct node *q);

int main(void)
{
	int i, j, key;
	printf("input number of data: ");
	scanf("%d", &num);
	struct node *x;
	listinitialize();
	for(i = 0, x = head; i < num; i++){
		printf("input key: ");
		scanf("%d", &key);
		x = insertafter(key, x);
	}

	printlist();

	printf("if you want something, input number:\n"
			"1.add data\n"
			"2.delete data\n"
			"3.print list\n"
			"4.exit\n");
	scanf("%d", &i);
	if(i == 1){
		printf("input key: ");
		scanf("%d", &key);
		x = insertafter(key, x);
	}
	else if(i == 2){
		printf("input data number that you want to delete: ");
		scanf("%d", &num);
		for(i = 1, x = head; i < num; i++){
			x = x->next;
		}
		deletenext(x);
	}
	else if(i == 3){
		printlist();
	}

	sort();
	printlist();

	return 0;
}

void sort(void)
{
	int i;
	struct node *x;
	x = (struct node *)malloc(sizeof(*x));

	for(i = 0; i < num; i++){
		for(x = head->next; x->next->next != NULL; x = x->next){
			if(x->key > x->next->key){
				exchange(x, x->next);
			}
		}
	}
}
void printlist(void)
{
	struct node *x;
	x = head;
	while(x->next->next != NULL){
		x = x->next;
		printf("%d ", x->key);
	}
	printf("\n");
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
}
