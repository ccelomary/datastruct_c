#ifndef STACK_H
#define	STACK_H

# include <stdlib.h>

typedef	struct	s_stack
{
	void		*data;
	struct s_stack	*next;
}			Stack;

void		push(Stack **stack, void *data);
void		*pop(Stack **stack);
void		*peek(const Stack *stack);
void		print_stack(const Stack *stack, void display_data(void *data));
void		clear_stack(Stack **stack, void free_data(void *data));
#endif
