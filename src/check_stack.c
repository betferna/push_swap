/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 11:56:54 by marad             #+#    #+#             */
/*   Updated: 2026/05/15 19:48:06 by user             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (!c)
		return (0);
	// if (c == '-')
		
	if (!((c >= '0' && c <= '9')))
		return (0);
	return (1);
}

int	ft_isflag(char *arg, t_opts *opts)
{
	if (!arg || (arg[0] != '-' && arg[1] != '-'))
		return (0);
	if (ft_strncmp(arg, "--bench", 7) == 0)
	{
		opts->bench = 1;
		return (1);
	}
	else if (p_flag(arg,opts))
		return (1);
	return (0);
}
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
	else if (ft_strncmp(arg, "--count_only", 13) == 0)
		opts->count.COUNT_ONLY=true;
	else
		return (0);
	return (1);
}

int	is_numb_flag(char *str, t_opts *opts)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (0);
	if (str[i])
	{
		if ((ft_isdigit(str[0])) || (ft_isflag(str, opts)))
			return (1);
		i++;
	}
	return (0);
}

int	no_duplicate(char **argvs)
{
	int			i;
	int			j;
	long long	first;
	long long	second;

	i = 0;
	while (argvs[i])
	{
		j = i + 1;
		first = ft_atoil(argvs[i]);
		while (argvs[j])
		{
			second = ft_atoil(argvs[j]);
			if (first == second)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	range_check(char **str)
{
	long long	n;

	n = ft_atoil((const char *)*str);
	if (n < INT_MIN || n > INT_MAX)
		return (0);
	return (1);
}
