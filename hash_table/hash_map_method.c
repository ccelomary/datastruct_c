#include "hash_map.h"

Map			*init_map(void)
{
	int	iter;
	Map	*map;

	iter = 0;
	map = malloc(sizeof(Map));
	while (iter < SIZE)
	{
		map->lst[iter] = NULL;
		iter++;
	}
	return (map);
}

int		get_hash_code(const void *key, size_t key_size)
{
	int		result;
	size_t		iter;
	unsigned char	*k;

	iter = 0;
	result = 0;
	k = (unsigned char *)key;
	while (iter < key_size)
	{
		result += k[iter] * 31;
		iter++;
	}
	return (result % SIZE);
}

void			*copy_key(const unsigned char *key, size_t key_size)
{
	size_t		iter;
	unsigned char	*dst;

	iter = 0;
	dst = malloc(key_size + 1);
	while (iter < key_size)
	{
		dst[iter] = key[iter];
		iter++;
	}
	dst[iter] = 0;
	return (dst);
}

void			set_value(Map *map, const void *key, void *value, size_t key_size)
{
	int		backet_id;
	key_value	*k_v;
	List		*list;

	backet_id = get_hash_code(key, key_size);
	if (map->lst[backet_id])
	{
		list = map->lst[backet_id];
		while (list)
		{
			if (compare(((key_value *)list->data)->key, key, key_size))
			{
				k_v = (key_value *)list->data;
				k_v->value = value;
				return ;
			}
			list = list->next;
		}
	}
	k_v = init_kv(copy_key(key, key_size), value);
	append(&map->lst[backet_id], k_v);
	return ;
}

void			*get_value(Map *map, const void *key, size_t key_size)
{
	int	id;
	List	*list;

	id = get_hash_code(key, key_size);
	if (!map->lst[id])
		return (NULL);
	list = map->lst[id];
	while (list)
	{
		if (compare(((key_value *)list->data)->key, key, key_size))
			return (((key_value *)list->data)->value);
		list = list->next;
	}
	return (NULL);
}

void			clear_map(Map **map, void free_data(void *kv))
{
	int	iter;

	iter = 0;
	if (!map)
		return ;
	while (iter < SIZE)
	{
		clear_list(&((*map)->lst[iter]), free_data);
		iter++;
	}
	free(*map);
	*map = NULL;
}
