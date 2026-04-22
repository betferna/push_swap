#include "push_swap.h"

void ft_push(t_stack *dst, t_stack *src)
{
	ft_lstadd_front(dst, src);
	ft_delone(src);
}


void	ft_lstadd_front(t_stack *lst, t_stack *new)
{
	if (!lst || !new)
		return ;
	new->next = lst;
	lst = new;
}
void	ft_delone(t_stack *lst)
{
	if (lst == NULL)
		return ;
	if (!lst)
		return ;
	free(lst);
}
