#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
} *head;

int main(void)
{
	head = (struct node*) malloc(sizeof(*head));
	int i = 3;
	head->data = i;

	return 0;
}
