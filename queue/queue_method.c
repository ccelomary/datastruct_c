#include "queue.h"

void	enqueue(Queue **q, void *data)
{
	Node	*temp;

	temp = malloc(sizeof(Node));
	temp->next = NULL;
	temp->prev = NULL;
	temp->data = data;
	if (!(*q))
	{
		*q = malloc(sizeof(Queue));
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

void	*dequeue(Queue *q)
{
	void	*data;
	Node	*temp;

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
		temp = q->tail;
		q->tail = q->tail->prev;
		q->tail->next = NULL;
		data = temp->data;
		free(temp);
	}
	return (data);
}

void	*peek(const Queue *q)
{
	if (!q || !q->head)
		return (NULL);
	return (q->tail->data);
}

void	print_queue(const Queue *q, void display(void *data))
{
	Node	*temp;

	if (!q || !q->head)
		return ;
	temp = q->head;
	while (temp)
	{
		display(temp->data);
		temp = temp->next;
	}
}

void	clear_queue(Queue **q)
{
	Node	*temp;
	Node	*before;

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
