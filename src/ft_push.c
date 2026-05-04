#include "push_swap.h"

void ft_push(t_stack **dst, t_stack **src)
{
	t_stack *tail;
	if (!dst || !src || !*src)
		return ;
	// while (tail->next != NULL)
	// 	tail = tail->next;
	tail = ft_lstlast(src);
	ft_lstadd_front(dst, &tail);
	ft_lstdellast(src);
	// ft_delone(src);
}
void	ft_lstdellast(t_stack **lst)
{
	t_stack *new_tail;
	t_stack *tail;
	if (!lst || !*lst)
		return ;
	tail = *lst;
	while (tail && tail->next != NULL)
	{
		if (tail && tail->next && tail->next->next == NULL)
			new_tail = tail;
		tail = tail->next;
	}
	if (!new_tail)
	{
		free(tail);
		tail = NULL;
	}
	new_tail->next = NULL;
	// free(temp);
}
t_stack	*ft_lstlast(t_stack **lst)
{
	t_stack *last = *lst;
	if (!lst || !*lst)
		return (*lst);
	while (last->next != NULL)
		last = last->next;
	return (last);
}

void	pa(t_stack **a, t_stack **b, t_counter *count)
{
	ft_push(a,b);
	write (1, "pa\n", 3);
	count->pa += 1;
	count->total += 1;
}

void	pb(t_stack **a, t_stack **b, t_counter *count)
{
	ft_push(b,a);
	write (1, "pb\n", 3);
	count->pb += 1;
	count->total += 1;
}


void	ft_lstadd_front(t_stack **lst, t_stack **new)
{
	if (!lst || !new || !*new)
		return ;
	(*new)->next = *lst;
	*lst = *new;
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
