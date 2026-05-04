#include "push_swap.h"

void ft_swap(t_stack **stack)
{
	int tmp;

	if (!stack || !*stack	)
		return ;
	tmp = (*stack)->next->value;
	(*stack)->next->value = (*stack)->value;
	(*stack)->value = tmp;
}

void sa(t_stack **a, t_counter *count)
{
	if (!a || !*a)
		return ;
	ft_swap(a);
	write (1, "sa\n", 3);
	count->sa += 1;
	count->total += 1;
}

void sb(t_stack **b, t_counter *count)
{
	if (!b)
		return ;
	ft_swap(b);
	write (1, "sb\n", 3);
	count->sb += 1;
	count->total += 1;
}

void ss(t_stack **a, t_stack **b, t_counter *count)
{
	if (!a || !b)
		return ;
	sa(a, count);
	sb(b, count);
	write (1, "ss\n", 3);
	count->ss += 1;
	count->total += 1;
}