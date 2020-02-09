/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 15:55:13 by mel-omar          #+#    #+#             */
/*   Updated: 2020/02/09 16:05:18 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>

typedef	struct		s_stack
{
	void			*data;
	struct s_stack	*next;
}					t_stack;

void				copy_data(void *dst, void *src, size_t len);
void				push(t_stack **stack, void *data);
void				*pop(t_stack **stack);
void				*peek(const t_stack *stack);
void				print_stack(const t_stack *stack,
		void display_data(void *data));
void				clear_stack(t_stack **stack, void free_data(void *data));
size_t				length(unsigned char *src);
#endif
