/* merge sort by linked list */
#include<stdio.h>
#include<stdlib.h>
#include"1112_5.c" //linked list program

struct node *msort(struct node *p);
struct node * merge(struct node *p, struct node *t2);

int main(int argc, char *argv[])
{
	int temp;
	FILE *file;
	listinitialize();//function from 1112_5.c
	struct node *t;
	t = head;

	file = fopen(argv[1], "r");
	while(1){//make linked list of file
		if(fscanf(file, "%d", &temp) == EOF){
			break;
		}
		t = insertafter(temp, t);//function from 1112_5.c
	}
	fclose(file);

	msort(head->next);//t->next == NULL now
	printlist();//function from 1112_5.c

	return 0;
}

struct node *msort(struct node *p)
/*first of array, last of array */
{
	if(p->next != NULL){
		struct node *t1;
		struct node *t2;
		t1 = p;
		t2 = p;
		while(t2->next->next != NULL && t2->next != NULL){
		//search middle point
			t1 = t1->next;
			t2 = t2->next->next;
		}
		t2 = t1->next;//initial of latter half
		t1->next = NULL; //first half's end become NULL
		p = msort(p); //first half
		t2 = msort(t2); //latter half
		p = merge(p, t2);
	}
	return p;
}

struct node *merge(struct node *p, struct node *t2)
/* first of FH, first of LH */
/* p array become main streem */
{
	struct node *first;
	first = p->prev;
	t2->prev = p->prev;
	while(p != NULL && t2 != NULL){
		if(p->key <= t2->key){
			p->prev->next = p;
			t2->prev = p;
			if(p->next != NULL){//p->next is end
				p->next->prev = p;
			}
			p = p->next;
		}
		else{//same condition as p
			t2->prev->next = t2;
			p->prev = t2;
			if(t2->next != NULL){
				t2->next->prev = t2;
			}
			t2 = t2->next;
		}
	}
	while(p != NULL){
		p->prev->next = p;
		if(p->next != NULL){//p->next is end
			p->next->prev = p;
		}
		p = p->next;
	}
	while(t2 != NULL){
		t2->prev->next = t2;
		if(t2->next != NULL){
			t2->next->prev = t2;
		}
		t2 = t2->next;
	}
	if(first != head){
		struct node *temp;
		temp = first->next;
		first->next = NULL;
		return temp;
	}
	else{
		return first->next;
	}
}
