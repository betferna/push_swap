/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 11:53:13 by marad             #+#    #+#             */
/*   Updated: 2026/05/15 19:35:51 by user             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*chosen_strategy(t_strategy s)
{
	if (s == STRATEGY_SIMPLE)
		return ("Simple");
	if (s == STRATEGY_MEDIUM)
		return ("Medium");
	if (s == STRATEGY_COMPLEX)
		return ("Complex");
	else
		return ("Adaptive");
}

char	*complexity_strategy(t_strategy s)
{
	if (s == STRATEGY_SIMPLE)
		return ("O(n2)");
	if (s == STRATEGY_MEDIUM)
		return ("O(n√n)");
	if (s == STRATEGY_COMPLEX)
		return ("O(n log n)");
	else
		return ("Adaptive");
}

void	print_bench(t_opts *opts, t_counter *count, double disorder)
{
	if (!opts->bench)
		return ;
	ft_printf_fd(2,"[bench] disorder:  %f %%\n", disorder);
	ft_printf_fd(2,"[bench] strategy: %s\n", chosen_strategy(opts->strategy));
	ft_printf_fd(2,"[bench] complexity: %s\n", complexity_strategy(opts->strategy));
	ft_printf_fd(2,"[bench] total_ops: %d\n", count->total);
	ft_printf_fd(2,"[bench] sa: %i  sb: %i  ss: %i  pa: %i  pb: %i\n",
		count->sa, count->sb, count->ss, count->pa, count->pb);
	ft_printf_fd(2,"[bench] ra: %i  rb: %i  rr: %i  rra: %i  rrb: %i  rrr: %i\n",
		count->ra, count->rb, count->rr, count->rra, count->rrb, count->rrr);
}
