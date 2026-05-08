/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 12:15:48 by betferna          #+#    #+#             */
/*   Updated: 2026/05/08 22:19:21 by user             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 12:15:48 by betferna          #+#    #+#             */
/*   Updated: 2026/05/08 22:12:11 by user             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int is_higher(t_stack *comp, t_stack *head)
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

void three_sort(t_stack **stack, t_counter *count)
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

void simple_sort(t_stack **a, t_stack **b, t_counter *count)
{
	int size;

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
}

void five_sort(t_stack **a, t_stack **b, t_counter *count)
{
	if (!a || !b || !count)
		return ;
}