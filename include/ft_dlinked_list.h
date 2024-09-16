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
t_dnode	*ft_dlist_append(t_dlist *list, void *data);
t_dnode	*ft_dlist_prepend(t_dlist *list, void *data);
t_dnode  *ft_dlist_find(t_dlist list, void *target, int (*eq)(void *data1, void *data2));
#endif
