#ifndef CIRCULAR_LIST_H
#define CIRCULAR_LIST_H
#include <stdlib.h>

typedef struct s_cnode
{
	void *data;
	struct	s_cnode *next;
}t_cnode;
typedef struct
{
	t_cnode *head;
	void (*free_node)(t_cnode *);
}t_circular_list;

void	circular_list_free(t_circular_list *list);
void	circular_list_foreach(const t_circular_list list, void callback(const t_cnode *));
t_cnode *circular_list_append(t_circular_list *list, void *data);
#endif
