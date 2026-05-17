/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 12:18:26 by marad             #+#    #+#             */
/*   Updated: 2026/05/17 14:47:31 by user             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_higher(t_stack *comp, t_stack *head)
{
	if (!comp || !head)
		return (0);
	while (head)
	{
		if (head->value > comp->value)
			return (0);
		head = head->next;
	}
	return (1);
}

void	simple_sort(t_stack **a, t_stack **b, t_counter *count)
{
	int	size;

	if (!a || !*a)
		return ;
	size = ft_lstsize(*a);
	if (size == 2)
	{
		if ((*a)->value > (*a)->next->value)
			sa(a, count);
	}
	else if (size == 3)
		three_sort(a, count);
	else if (size <= 5)
		five_sort(a, b, count);
	else
		sort_large(a, b, count);
}

void	sort_large(t_stack **a, t_stack **b, t_counter *count)
{
	while (ft_lstsize(*a) > 5)
	{
		min_top(a, count);
		pb(a, b, count);
	}
	five_sort(a, b, count);
	while (*b)
		pa(a, b, count);
}

int	find_min(t_stack *stack)
{
	int	min;

	min = stack->value;
	while (stack)
	{
		if (min > stack->value)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}
