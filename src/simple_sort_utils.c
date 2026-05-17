/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 12:18:26 by marad             #+#    #+#             */
/*   Updated: 2026/05/17 15:17:41 by user             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	five_sort(t_stack **a, t_stack **b, t_counter *count)
{
	int	min;

	if (!a || !b || !count)
		return ;
	while (ft_lstsize(*a) > 3)
	{
		min = find_min(*a);
		while ((*a)->value != min)
			ra(a, count);
		pb(a, b, count);
	}
	three_sort(a, count);
	if (ft_lstsize(*b) < 2)
		pa(a, b, count);
	else if ((*b)->value > (*b)->next->value)
	{
		pa(a, b, count);
		pa(a, b, count);
	}
	else
	{
		ra(b, count);
		pa(a, b, count);
		pa(a, b, count);
	}
}

void	three_sort(t_stack **stack, t_counter *count)
{
	if (!stack || !*stack || ft_lstsize(*stack) != 3)
		return ;
	if (is_higher(*stack, *stack))
		ra(stack, count);
	else if (is_higher((*stack)->next, *stack))
		rra(stack, count);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack, count);
}

void	min_top(t_stack **a, t_counter *count)
{
	t_stack		*tmp;
	int			min_val;
	int			min_pos;
	int			size;

	tmp = *a;
	min_val = tmp->value;
	min_pos = 0;
	min_pos = ft_min_pos(min_pos, min_val, tmp);
	size = ft_lstsize(*a);
	if (min_pos <= size / 2)
		while (min_pos-- > 0)
			ra(a, count);
	else
		while (size - min_pos++ > 0)
			rra(a, count);
}

int	ft_min_pos(int min_pos, int min_val, t_stack *tmp)
{
	int	i;

	i = 0;
	while (tmp)
	{
		if (tmp->value < min_val)
		{
			min_val = tmp->value;
			min_pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (min_pos);
}
