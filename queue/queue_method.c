/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_method.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 15:54:29 by mel-omar          #+#    #+#             */
/*   Updated: 2020/02/09 17:45:06 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

void	enqueue(t_queue **q, void *data)
{
	t_node	*temp;

	temp = malloc(sizeof(t_node));
	temp->next = NULL;
	temp->prev = NULL;
	temp->data = data;
	if (!(*q))
	{
		*q = malloc(sizeof(t_queue));
		(*q)->head = NULL;
		(*q)->tail = NULL;
	}
	if (!(*q)->head)
	{
		(*q)->head = temp;
		(*q)->tail = (*q)->head;
	}
	else
	{
		temp->prev = (*q)->tail;
		(*q)->tail->next = temp;
		(*q)->tail = (*q)->tail->next;
	}
}

void	*dequeue(t_queue *q)
{
	void	*data;
	t_node	*temp;

	if (!q || !q->head)
		return (NULL);
	if (!q->head->next)
	{
		data = q->head->data;
		free(q->head);
		q->head = NULL;
		q->tail = NULL;
	}
	else
	{
		temp = q->head;
		q->head = q->head->next;
		data = temp->data;
		free(temp);
	}
	return (data);
}

void	*peek(const t_queue *q)
{
	if (!q || !q->head)
		return (NULL);
	return (q->tail->data);
}

void	print_queue(const t_queue *q, void display(void *data))
{
	t_node	*temp;

	if (!q || !q->head)
		return ;
	temp = q->head;
	while (temp)
	{
		display(temp->data);
		temp = temp->next;
	}
}

void	clear_queue(t_queue **q)
{
	t_node	*temp;
	t_node	*before;

	if (*q && (*q)->head)
	{
		temp = (*q)->tail;
		while (temp)
		{
			before = temp->prev;
			free(temp);
			temp = before;
		}
	}
	if (*q)
	{
		free(*q);
		q = NULL;
	}
}
