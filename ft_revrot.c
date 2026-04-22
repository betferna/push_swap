#include "push_swap.h"

//move the tail to the front:
static void	revrot(t_stack **stack)
{
	t_stack *tail;

	if (!stack || !*stack || !(*stack)->next)
		return;
	tail = *stack;
	while (tail -> next != NULL)
		tail = tail->next;
	tail->prev->next = NULL;
	ft_stack_add_front(stack, tail);
}

void ft_rra(t_stack **a)
{
	revrot(a);
	write (1, "rra\n", 4);
}

void ft_rrb(t_stack **b)
{
	revrot(b);
	write (1, "rrb\n", 4);
}

void ft_rrr(t_stack **a, t_stack **b)
{
	revrot(a);
	revrot(b);
	write (1, "rrr\n", 4);
}