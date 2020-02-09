#include "hash_map.h"

List	*get_keys(const Map *map)
{
	List		*list;
	List		*lst;
	int		iter;
	unsigned char	*key;

	iter = 0;
	list = NULL;
	while (iter < SIZE)
	{
		lst = map->lst[iter];
		while (lst)
		{
			key = ((key_value *)lst->data)->key;
			append(&list, key);
			lst = lst->next;
		}
		iter++;
	}
	return (list);
}
