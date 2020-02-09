#ifndef HASH_MAP_H
#define HASH_MAP_H
#define	SIZE 31

#include "../linkedlist/linkedlist.h"

typedef struct	s_key_value
{
	void	*key;
	void	*value;
}		key_value;

typedef struct	s_hash_map
{
	int	size;
	List	*lst[SIZE];
}		Map;

Map		*init_map(void);
int		compare(const void *val1, const void *val2, size_t key_size);
key_value	*init_kv(void *key, void *value);
void		free_kv(void *k_v);
void		set_value(Map *map, const void *key, void *value, size_t key_size);
void		*get_value(Map *map, const void *key, size_t key_size);
List		*get_keys(const Map *map);
void		clear_map(Map **map, void free_data(void *k_v));
#endif
