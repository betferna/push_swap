/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 11:50:27 by marad             #+#    #+#             */
/*   Updated: 2026/05/13 03:04:06 by user             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	p_flag(char *arg, t_opts *opts)
{
	if (!arg || (arg[0] != '-' && arg[1] != '-'))
		return (0);
	if (ft_strncmp(arg, "--simple", 9) == 0)
		opts->strategy = STRATEGY_SIMPLE;
	else if (ft_strncmp(arg, "--medium", 9) == 0)
		opts->strategy = STRATEGY_MEDIUM;
	else if (ft_strncmp(arg, "--complex", 10) == 0)
		opts->strategy = STRATEGY_COMPLEX;
	else if (ft_strncmp(arg, "--adaptive", 11) == 0)
		opts->strategy = STRATEGY_ADAPTIVE;
	else if (ft_strncmp(arg, "--bench", 8) == 0)
		opts->bench = 1;
	else
		return (0);
	return (1);
}

void	dispatch_strategy(t_stack **a, t_stack **b,
	t_opts *opts, t_counter *count)
{
	if (opts->strategy == STRATEGY_SIMPLE)
		simple_sort(a, b, count);
	else if (opts->strategy == STRATEGY_MEDIUM)
		medium_sort(a, b, count);
	else if (opts->strategy == STRATEGY_COMPLEX)
		complex_sort(a, b, count);
	else if (opts->strategy == STRATEGY_ADAPTIVE)
		opts->strategy = adaptive_sort(a, b, count);
	else
		return ;
}

t_strategy	adaptive_sort(t_stack **a, t_stack **b, t_counter *count)
{
	double	disorder;

	disorder = comp_disorder(a);
	if (disorder < 0.2)
	{
		simple_sort(a, b, count);
		return (STRATEGY_SIMPLE);
	}
	else if (disorder < 0.5)
	{
		medium_sort(a, b, count);
		return (STRATEGY_MEDIUM);
	}
	else
	{
		complex_sort(a, b, count);
		return (STRATEGY_COMPLEX);
	}
}
