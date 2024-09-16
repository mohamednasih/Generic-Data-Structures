#ifndef FT_DLINKED_LIST_H
#define FT_DLINKED_LIST_H

#include <stdlib.h>

typedef struct s_dnode
{
	void	*data;
	struct s_dnode	*next;
	struct s_dnode	*prev;
}t_dnode;

typedef struct s_dlist
{
	t_dnode	*head;
	void (*destroy)(t_dnode *);
}t_dlist;

void	foreach_dlist(t_dlist dlist, void (*f)(t_dnode *));
#endif
