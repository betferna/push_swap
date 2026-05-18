/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_swap.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: user <user@student.42seoul.kr>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/05/12 12:09:48 by marad         #+#    #+#                 */
/*   Updated: 2026/05/18 13:06:04 by marad         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack **stack)
{
	int	tmp;

	if (!stack || !*stack)
		return ;
	tmp = (*stack)->next->value;
	(*stack)->next->value = (*stack)->value;
	(*stack)->value = tmp;
}

void	sa(t_stack **a, t_counter *count)
{
	if (!a || !*a)
		return ;
	ft_swap(a);
	if (!count->count_only)
		write(1, "sa\n", 3);
	count->sa += 1;
	count->total += 1;
}

void	sb(t_stack **b, t_counter *count)
{
	if (!b)
		return ;
	ft_swap(b);
		if (!count->count_only)
		write(1, "sb\n", 3);
	count->sb += 1;
	count->total += 1;
}

void	ss(t_stack **a, t_stack **b, t_counter *count)
{
	if (!a || !b)
		return ;
	ft_swap(a);
	ft_swap(b);
	if (!count->count_only)
		write(1, "ss\n", 3);
	count->ss += 1;
	count->total += 1;
}
