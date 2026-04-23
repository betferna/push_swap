#include "push_swap.h"

void ft_push(t_stack **dst, t_stack **src)
{
	t_stack *tmp;

	if (!src || !*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	ft_stack_add_front(dst, tmp);
}

// void	ft_lstadd_front(t_stack *lst, t_stack *new)
// {
// 	if (!lst || !new)
// 		return ;
// 	new->next = lst;
// 	lst = new;
// }
// void	ft_delone(t_stack *lst)
// {
// 	if (lst == NULL)
// 		return ;
// 	free(lst);
// }

void pa(t_stack **a, t_stack **b)
{
	ft_push(a, b);
	write (1, "pa\n", 3);
}

void pb(t_stack **a, t_stack **b)
{
	ft_push(b, a);
	write (1, "pb\n", 3);
}