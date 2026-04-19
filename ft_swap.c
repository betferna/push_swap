#include "push_swap.h"

void ft_swap(t_stack *a)
{
	int tmp;
	t_stack *first;

	if (!a)
		return ;
	tmp = a->next->value;
	a->next->value = a->value;
	a->value = tmp;
}

void ft_sa(t_stack *a)
{
	if (!a)
		return ;
	ft_swap(a);
	write (1, "sa ", 3);
}

void ft_sb(t_stack *b)
{
	if (!b)
		return ;
	ft_swap(b);
	write (1, "sb ", 3);
}

void ft_ss(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ;
	ft_sa(a);
	ft_sb(b);
	write (1, "ss ", 3);
}