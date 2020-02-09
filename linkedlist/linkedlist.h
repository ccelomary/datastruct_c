/***********************/
/* Mohamed Elomary     */	
/***********************/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

# include <stdlib.h>

typedef struct 		s_list
{
	void		*data;
	struct s_list	*next;
}			List;

void			append(List **list, void *data);
void			*pop(List **list);
void			iterate_list(const List *list, void func(void *data));
void			clear_list(List **list, void free_data(void *));
size_t			length(const List *lst);
#endif
