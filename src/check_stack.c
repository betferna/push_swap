#include "push_swap.h"

/*
all functions return 1 if positive, 0 is faulty
need libft for libft functions
*/
int	ft_isdigit(int c)
{
	// int i;

	// i = 0;
	// if (c == '-' || c == '+')
    //     i++;
	if (!c)
        return (0);
	if (!((c >= '0' && c <= '9')))
		return (0);
	return (1);
}

int ft_isflag(char *arg)
{
	if (!arg || (arg[0] != '-' && arg[1] != '-'))
        return (0);
    else if ((ft_strncmp(arg, "--simple", 9) == 0) ||
		(ft_strncmp(arg, "--medium", 8) == 0) ||
		(ft_strncmp(arg, "--complex", 9) == 0) ||
		(ft_strncmp(arg, "--adaptive", 10) == 0) ||
		(ft_strncmp(arg, "--bench", 7) == 0))
		return (1);
	return (0);
}

int is_numb_flag(char *str)
{
	int i;

	i = 0;
	if (!str || !str[0])
		return (0);
	if (str[i])
	{
		if ((ft_isdigit(str[0])) || (ft_isflag(str)))
			return (1);
		i++;
	}
	return (0);
}

int no_duplicate(char **argvs)
{
	int i;
	int j;
	long long first;
	long long second;

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

int range_check(char **str)
{
	long long n;

	n = ft_atoil((const char *)*str);
	if (n < INT_MIN || n > INT_MAX)
		return (0);
	return (1);
}

int is_stack_stored(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}