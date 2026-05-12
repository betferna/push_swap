/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: marad <marad@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/05/12 12:13:43 by marad         #+#    #+#                 */
/*   Updated: 2026/05/12 12:14:29 by marad         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	if (!stack)
		return ;
	while (stack)
	{
		printf("%d\n", stack->value);
		stack = stack->next;
	}
	printf("\n");
}

t_stack	*ft_stack_new(int value)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->next = NULL;
	return (node);
}

void	ft_stack_add_front(t_stack **stack, t_stack *newhead)
{
	if (!stack || !newhead)
		return ;
	newhead->next = *stack;
	*stack = newhead;
}

void	ft_stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!new || !stack)
		return ;
	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = new;
}

t_stack	*init_stack(char **temp, t_opts *opts)
{
	t_stack	*a;
	int		i;

	a = NULL;
	i = 0;
	if (!temp)
		return (NULL);
	while (temp[i])
	{
		if (p_flag(temp[i], opts))
		{
			i++;
			continue ;
		}
		ft_stack_add_back(&a, ft_stack_new((int)ft_atoil(temp[i])));
		i++;
	}
	return (a);
}
