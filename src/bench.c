/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bench.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: marad <marad@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/05/12 11:53:13 by marad         #+#    #+#                 */
/*   Updated: 2026/05/12 11:56:32 by marad         ########   odam.nl         */
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
	ft_printf("[bench] disorder:  %.2f%%\n", disorder * 100);
	ft_printf("[bench] strategy: %s\n", chosen_strategy(opts->strategy));
	ft_printf("[bench] complexity: %s\n", complexity_strategy(opts->strategy));
	ft_printf("[bench] total_ops: %d\n", count->total);
	ft_printf("[bench] sa: %i  sb: %i  ss: %i  pa: %i  pb: %i\n",
		count->sa, count->sb, count->ss, count->pa, count->pb);
	ft_printf("[bench] ra: %i  rb: %i  rr: %i  rra: %i  rrb: %i  rrr: %i\n",
		count->ra, count->rb, count->rr, count->rra, count->rrb, count->rrr);
		// -> they all need to print to stderr instead of stdout? 
		// Numbers are inccorect with running/could there be a bug in ft_printf?
		// no f type in ft_printf?
}
