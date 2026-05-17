/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 12:15:38 by marad             #+#    #+#             */
/*   Updated: 2026/05/17 16:02:49 by user             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long int	ft_atoil(const char *str)
{
	size_t				i;
	int					min;
	unsigned long long	res;

	i = 0;
	min = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			min *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + str[i] - '0';
		if (res > (unsigned long long)LLONG_MAX && min == 1)
			return (-1);
		if (res > (unsigned long long)LLONG_MAX + 1 && min == -1)
			return (0);
		i++;
	}
	return ((long long int)min * res);
}

int	ft_check_valid(int argc, char **argvs, t_opts *opts)
{
	int	i;
	int	numbers_start;

	i = 1 + count_flags(argc, argvs, opts);
	numbers_start = i;
	while (i < argc)
	{
		if (!is_numb_flag(argvs[i], opts) || ((ft_atoil(argvs[i]) > INT_MAX)
				|| (ft_atoil(argvs[i]) < INT_MIN)))
		{
			write(2, "Error\n", 6);
			return (0);
		}
		i++;
	}
	if (!no_duplicate(argvs + numbers_start))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}

// if ((*argvs[i] == '-') && (ft_isdigit((int)*argvs[i + 1]))
//	&& *argvs[i + 1] != '\0')
// 	i+=2;
t_stack	*ft_parse(int argc, char **argvs, t_stack *a, t_opts *opts)
{
	char	**temp;

	if (argc == 2 + count_flags(argc, argvs, opts))
	{
		temp = ft_split(argvs[1 + count_flags(argc, argvs, opts)], ' ');
	}
	else
		temp = argvs + 1 + count_flags(argc, argvs, opts);
	a = init_stack(temp, opts);
	if (!a)
	{
		if (argc == 2 + count_flags(argc, argvs, opts))
			free_temp(temp);
		write(2, "Error\n", 6);
		return (NULL);
	}
	if (argc == 2 + count_flags(argc, argvs, opts))
		free_temp(temp);
	return (a);
}

int	count_flags(int argc, char **argvs, t_opts *opts)
{
	int	flags;
	int	i;

	i = 1;
	flags = 0;
	while (i < argc - 1 && ft_isflag(argvs[i], opts))
	{
		i++;
		flags++;
	}
	return (flags);
}

int	main(int argc, char **argvs)
{
	t_stack	*a;
	t_stack	*b;
	t_opts	opts;
	double	disorder;

	if (argc < 2)
		return (0);
	ft_memset(&opts, 0, sizeof(t_opts));
	opts.strategy = STRATEGY_ADAPTIVE;
	opts.bench = 0;
	a = NULL;
	b = NULL;
	if (!ft_check_valid(argc, argvs, &opts))
		return (1);
	a = ft_parse(argc, argvs, a, &opts);
	if (!a)
		return (1);
	disorder = comp_disorder(&a) * 100;
	if (disorder == 0.0)
		return (0);
	dispatch_strategy(&a, &b, &opts, &opts.count);
	print_bench(&opts, &opts.count, disorder);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
