/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_revrot.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: user <user@student.42seoul.kr>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/05/12 12:07:15 by marad         #+#    #+#                 */
/*   Updated: 2026/05/18 13:03:59 by marad         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_revrot(t_stack **stack)
{
	t_stack	*tail;
	t_stack	*new_tail;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tail = *stack;
	while (tail->next != NULL)
	{
		if (tail->next->next == NULL)
			new_tail = tail;
		tail = tail->next;
	}
	ft_stack_add_front(stack, tail);
	new_tail->next = NULL;
}

void	rra(t_stack **a, t_counter *count)
{
	ft_revrot(a);
	if (!count->count_only)
		write(1, "rra\n", 4);
	count->rra += 1;
	count->total += 1;
}

void	rrb(t_stack **b, t_counter *count)
{
	ft_revrot(b);
	if (!count->count_only)
		write(1, "rrb\n", 4);
	count->rrb += 1;
	count->total += 1;
}

void	rrr(t_stack **a, t_stack **b, t_counter *count)
{
	ft_revrot(a);
	ft_revrot(b);
	if (!count->count_only)
		write(1, "rrr\n", 4);
	count->rrr += 1;
	count->total += 1;
}
