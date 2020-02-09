/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_method2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 16:01:49 by mel-omar          #+#    #+#             */
/*   Updated: 2020/02/09 16:03:23 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	print_stack(const t_stack *stack, void display_data(void *data))
{
	if (stack)
	{
		display_data(stack->data);
		print_stack(stack->next, display_data);
	}
}

void	copy_data(void *dst, void *src, size_t len)
{
	size_t			iter;
	unsigned char	*d;
	unsigned char	*s;

	iter = 0;
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (iter < len)
	{
		d[iter] = s[iter];
		iter++;
	}
}

size_t	length(unsigned char *src)
{
	size_t	len;

	len = 0;
	while (src[len])
		len++;
	return (len);
}
