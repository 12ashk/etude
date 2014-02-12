/*linked list*/
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
void deletenext(struct node *p);
void sort(void);
void exchange(struct node *p, struct node *q);

int main(void)
{
	int i, j, num, key;
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

	while(1){
		printf("if you want something, input number:\n"
				"1.add data\n"
				"2.delete data\n"
				"3.print list\n"
				"4.sort list\n"
				"5.exit\n");
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
			for(; x->next != head; x = x->next){
			}
		}
		else if(i == 3){
			printlist();
		}
		else if(i == 4){
			sort();
		}
		else{
			break;
		}
	}

	return 0;
}

void sort(void)
{
	struct node *x, *y;
	for(x = head; x->prev != head; x = x->prev){
		for(y = head->next; y->next != head; y = y->next){
			if(y->key > y->next->key){
				exchange(y, y->next);
			}
		}
	}
	printlist();
}

void printlist(void)
{
	struct node *x;
	x = head;
	while(x->next != head){
		x = x->next;
		printf("%d ", x->key);
	}
	printf("\n");
}

void listinitialize(void)
{
	head = (struct node*) malloc(sizeof(*head));
	head->next = head;
	head->prev = head;
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

void deletenext(struct node *p)
{
	if(p->next == head){
		printf("ERROR\n");
	}
	else{
		struct node *x;
		x = p->next;
		p->next = p->next->next;
		p->next->next->prev = p;
		free(x);
	}
}

void exchange(struct node *p, struct node *q)
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(*temp));
	temp->key = p->key;
	p->key = q->key;
	q->key = temp->key;
}
