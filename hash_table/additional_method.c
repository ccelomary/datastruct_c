#include "hash_map.h"

int		compare(const void *val1,const void *val2, size_t key_size)
{
	size_t		iter;
	unsigned char	*v1;
	unsigned char	*v2;

	v1 = (unsigned char *)val1;
	v2 = (unsigned char *)val2;
	iter = 0;
	while (v1[iter] == v2[iter] && iter < key_size)
		iter++;
	if (iter != key_size)
		return (0);
	return (1);
}

key_value	*init_kv(void *key, void *value)
{
	key_value	*k_v;
	size_t		len;

	k_v = malloc(sizeof(key_value));
	k_v->key = key;
	k_v->value = value;
	return (k_v);
}
