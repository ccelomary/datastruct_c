/******************/
/* Mohmed Elomary */
/******************/

#include "linkedlist.h"

void	append(List **list, void *data)
{
	List	*temp;
	List	*before;

	temp = malloc(sizeof(List));
	temp->data = data;
	temp->next = NULL;
	if (!(*list))
		*list = temp;
	else
	{
		before = *list;
		while (before->next)
			before = before->next;
		before->next = temp;
	}
}

void	*pop(List **list)
{
	void	*data;
	List	*before;
	List	*temp;
	data = NULL;
	if (!(*list))
		return (data);
	if (!((*list)->next))
	{
		data = (*list)->data;
		free(*list);
		*list = NULL;
	}
	else
	{
		before = (*list)->next;
		temp = *list;
		while (before->next)
		{
			temp = before;
			before = before->next;
		}
		temp->next = NULL;
		data = before->data;
		free(before);
	}
	return (data);
}

void	iterate_list(const List *list, void func(void *data))
{
	List	*temp;

	temp = (List *)list;
	while (temp)
	{
		func(temp->data);
		temp = temp->next;
	}
}

void	clear_list(List **list, void free_data(void *data))
{
	if (!*list)
		return ;
	if ((*list)->next)
		clear_list(&((*list)->next), free_data);
	free_data((*list)->data);
	free(*list);
	*list = NULL;
}

size_t	length(const List *list)
{
	size_t	len;
	List	*lst;

	lst = (List *)list;
	len = 0;
	while (lst)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}
