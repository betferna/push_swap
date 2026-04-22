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
}

void ft_ra(t_stack **a)
{
	rotate(a);
	write (1, "ra\n", 3);
}

void ft_rb(t_stack **b)
{
	rotate(b);
	write (1, "rb\n", 3);
}

void ft_rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	write (1, "rr\n", 3);
}
