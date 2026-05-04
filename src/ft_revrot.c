#include "push_swap.h"

//move the tail to the front:
void	ft_revrot(t_stack **stack)
{
	t_stack *tail;
	t_stack *new_tail;

	if (!stack || !*stack || !(*stack)->next)
		return;
	tail = *stack;
	while (tail -> next != NULL)
	{
		if (tail->next->next == NULL)
			new_tail = tail;
		tail = tail->next;
	}
	ft_stack_add_front(stack, tail);
	new_tail->next = NULL;
}

void rra(t_stack **a, t_counter *count)
{
	ft_revrot(a);
	write (1, "rra\n", 4);
	count->rra += 1;
	count->total += 1;
}

void rrb(t_stack **b, t_counter *count)
{
	ft_revrot(b);
	write (1, "rrb\n", 4);
	count->rrb += 1;
	count->total += 1;
}

void rrr(t_stack **a, t_stack **b, t_counter *count)
{
	ft_revrot(a);
	ft_revrot(b);
	write (1, "rrr\n", 4);
	count->rrr += 1;
	count->total += 1;
}

