/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 15:53:01 by mel-omar          #+#    #+#             */
/*   Updated: 2020/02/09 15:54:04 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H

# include <stdlib.h>

typedef struct		s_node
{
	void			*data;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct		s_queue
{
	t_node			*head;
	t_node			*tail;
}					t_queue;

void				enqueue(t_queue **q, void *data);
void				*dequeue(t_queue *q);
void				*peek(const t_queue *q);
void				print_queue(const t_queue *q, void f(void *data));
void				clear_queue(t_queue **q);
#endif
