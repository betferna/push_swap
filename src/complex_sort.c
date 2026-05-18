/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   complex_sort.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: marad <marad@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/05/12 12:01:01 by marad         #+#    #+#                 */
/*   Updated: 2026/05/18 15:47:41 by marad         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index(t_stack **a)
{
	int		count;
	t_stack	*node_i;
	t_stack	*node_j;

	if (!a || !*a)
		return ;
	node_i = *a;
	while (node_i != NULL)
	{
		node_j = *a;
		count = 0;
		while (node_j != NULL)
		{
			if (node_j->value < node_i->value)
				count++;
			node_j = node_j->next;
		}
		node_i->index = count;
		node_i = node_i->next;
	}
}

int	calc_max_bits(int n)
{
	int	bit_position;
	int	val;

	bit_position = 0;
	val = n - 1;
	while ((val >> bit_position) != 0)
		bit_position++;
	return (bit_position);
}

void	complex_sort(t_stack **a, t_stack **b, t_counter *count)
{
	int	n;

	n = ft_stacksize(*a);
	if (n < 2)
		return ;
	assign_index(a);
	complex_helper(a, b, count, n);
}

void	complex_helper(t_stack **a, t_stack **b, t_counter *count, int n)
{
	int	bit_position;
	int	max_bits;
	int	i;

	max_bits = calc_max_bits(n);
	bit_position = 0;
	while (bit_position < max_bits)
	{
		i = 0;
		while (i++ < n)
		{
			if ((((*a)->index >> bit_position) & 1) == 0)
				pb(a, b, count);
			else
				ra(a, count);
		}
		while (*b)
		{
			pa(a, b, count);
		}
		bit_position++;
	}
}
