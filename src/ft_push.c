/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_push.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: user <user@student.42seoul.kr>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/05/12 12:04:11 by marad         #+#    #+#                 */
/*   Updated: 2026/05/18 13:02:30 by marad         ########   odam.nl         */
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

void	pa(t_stack **a, t_stack **b, t_counter *count)
{
	ft_push(a, b);
	if (!count->count_only)
		write(1, "pa\n", 3);
	// else
	// 	write(2, "pa\n", 3);
	count->pa += 1;
	count->total += 1;
}

void	pb(t_stack **a, t_stack **b, t_counter *count)
{
	ft_push(b, a);
	if (!count->count_only)
		write(1, "pb\n", 3);
	// else
	// 	write(2, "pb\n", 3);
	count->pb += 1;
	count->total += 1;
}
