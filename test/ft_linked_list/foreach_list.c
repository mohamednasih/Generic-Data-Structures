#include <stdlib.h>
#include <stdio.h>
#include "ft_linked_list.h"

void print(void * data)
{
	int *d = data;
	printf("%d ->",*d);
}	
int main()
{
	t_node *head = malloc(sizeof(t_node));
	int *h = malloc(sizeof(int));		
	*h = 1;
	head->data = h;	


	t_node *a = malloc(sizeof(t_node));
	int *adata = malloc(sizeof(int));		
	*adata = 2;
	a->data = adata;
	head->next = a;

	t_node *b = malloc(sizeof(t_node));
	int *bdata = malloc(sizeof(int));		
	*bdata = 3;
	b->data = bdata;
	a->next = b;
	
	t_node *c = malloc(sizeof(t_node));
	int *cdata = malloc(sizeof(int));		
	*cdata = 4;
	c->data = cdata;	
	b->next = c;
	c->next = NULL;
	
	foreach_list(head,print);
}
