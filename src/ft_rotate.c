#include "push_swap.h"

//move head to back:
void	rotate(t_stack **stack)
{
	t_stack *head;

	if (!stack || !*stack || !(*stack)->next)
		return;
	head = *stack;
	*stack = head->next;
	ft_stack_add_back(stack, head);
	head->next = NULL;
}

void ra(t_stack **a, t_counter *count)
{
	rotate(a);
	write (1, "ra\n", 3);
	count->ra += 1;
	count->total += 1;
}

void rb(t_stack **b, t_counter *count)
{
	rotate(b);
	write (1, "rb\n", 3);
	count->rb += 1;
	count->total += 1;
}

void rr(t_stack **a, t_stack **b, t_counter *count)
{
	rotate(a);
	rotate(b);
	write (1, "rr\n", 3);
	count->rr += 1;
	count->total += 1;
}
