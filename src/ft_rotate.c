/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_rotate.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: user <user@student.42seoul.kr>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/05/12 12:08:12 by marad         #+#    #+#                 */
/*   Updated: 2026/05/18 13:06:48 by marad         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*head;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	head = *stack;
	*stack = head->next;
	ft_stack_add_back(stack, head);
	head->next = NULL;
}

void	ra(t_stack **a, t_counter *count)
{
	rotate(a);
	if (!count->count_only)
		write(1, "ra\n", 3);
	count->ra += 1;
	count->total += 1;
}

void	rb(t_stack **b, t_counter *count)
{
	rotate(b);
	if (!count->count_only)
		write(1, "rb\n", 3);
	count->rb += 1;
	count->total += 1;
}

void	rr(t_stack **a, t_stack **b, t_counter *count)
{
	rotate(a);
	rotate(b);
	if (!count->count_only)
		write(1, "rr\n", 3);
	count->rr += 1;
	count->total += 1;
}
