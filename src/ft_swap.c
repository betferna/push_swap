#include "push_swap.h"

void ft_swap(t_stack *a)
{
	int tmp;

	if (!a)
		return ;
	tmp = a->next->value;
	a->next->value = a->value;
	a->value = tmp;
}

void sa(t_stack *a)
{
	if (!a)
		return ;
	ft_swap(a);
	write (1, "sa ", 3);
}

void sb(t_stack *b)
{
	if (!b)
		return ;
	ft_swap(b);
	write (1, "sb ", 3);
}

void ss(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ;
	sa(a);
	sb(b);
	write (1, "ss ", 3);
}