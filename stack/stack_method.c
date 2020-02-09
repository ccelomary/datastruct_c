#include "stack.h"

void	copy_data(void *dst, void *src, size_t len)
{
	size_t		iter;
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

void	push(Stack **stack, void *data)
{
	Stack	*temp;
	void	*d;
	size_t	len;

	temp = malloc(sizeof(Stack));
	len = length(data);
	d = malloc(((len > 8) ? len : 8));
	copy_data(d, data, ((len > 8) ? len : 8));
	temp->data = d;
	temp->next = NULL;
	if (!(*stack))
		*stack = temp;
	else
	{
		temp->next = *stack;
		*stack = temp;
	}
}

void	*pop(Stack **stack)
{
	void	*data;
	Stack	*next;

	if (!(*stack))
		return (NULL);
	data = (*stack)->data;
	next = (*stack)->next;
	free(*stack);
	*stack = next;
	return (data);
}

void	*peek(const Stack *stack)
{
	if (stack)
		return (stack->data);
	return (NULL);
}

void	print_stack(const Stack *stack, void display_data(void *data))
{
	if (stack)
	{
		display_data(stack->data);
		print_stack(stack->next, display_data);
	}
}

void	clear_stack(Stack **stack, void free_data(void *data))
{
	if (*stack)
	{
		clear_stack(&(*stack)->next, free_data);
		free_data((*stack)->data);
		free(*stack);
		*stack = NULL;
	}
}
