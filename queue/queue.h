#ifndef QUEUE_H
#define QUEUE_H

# include <stdlib.h>

typedef struct		s_node
{
	void		*data;
	struct s_node	*next;
	struct s_node	*prev;
}			Node;

typedef struct		s_queue
{
	Node		*head;
	Node		*tail;
}			Queue;

void			enqueue(Queue **q, void *data);
void			*dequeue(Queue *q);
void			*peek(const Queue *q);
void			print_queue(const Queue *q, void f(void *data));
void			clear_queue(Queue **q);
#endif
