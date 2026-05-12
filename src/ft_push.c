/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_push.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: marad <marad@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/05/12 12:04:11 by marad         #+#    #+#                 */
/*   Updated: 2026/05/12 12:06:55 by marad         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack **dst, t_stack **src)
{
	t_stack	*tmp;

	if (!dst || !src || !*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	ft_stack_add_front(dst, tmp);
}

void	ft_lstdellast(t_stack **lst)
{
	t_stack	*new_tail;
	t_stack	*tail;

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
}

void	pa(t_stack **a, t_stack **b, t_counter *count)
{
	ft_push(a, b);
	write (1, "pa\n", 3);
	count-> pa += 1;
	count-> total += 1;
}

void	pb(t_stack **a, t_stack **b, t_counter *count)
{
	ft_push(b, a);
	write (1, "pb\n", 3);
	count->pb += 1;
	count->total += 1;
}
