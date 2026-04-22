#include "push_swap.h"

void ft_swap(t_stack **stack)
{
	int tmp;

	if (!stack)
		return ;
	tmp = (*stack)->next->value;
	(*stack)->next->value = (*stack)->value;
	(*stack)->value = tmp;
}

void sa(t_stack **a)
{
	if (!a || !*a)
		return ;
	ft_swap(a);
	write (1, "sa\n", 3);
}

void sb(t_stack **b)
{
	if (!b)
		return ;
	ft_swap(b);
	write (1, "sb\n", 3);
}

void ss(t_stack **a, t_stack **b)
{
	if (!a || !b)
		return ;
	sa(a);
	sb(b);
	write (1, "ss\n", 3);
}