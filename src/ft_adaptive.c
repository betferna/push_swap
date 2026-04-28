#include "push_swap.h"

int p_flag(char *arg, t_strategy *output)
{
    if (arg[0] == '-' && arg[1] == '-')
    {
        if (ft_strncmp(arg, "--simple", 8) == 0 && arg[8] == '\0')
        {
            *output = STRATEGY_SIMPLE;
            return (1); 
        }
        else if (ft_strncmp(arg, "--medium", 8) == 0 && arg[8] == '\0')
        {
            *output = STRATEGY_MEDIUM;
            return (1); 
        }
        else if (ft_strncmp(arg, "--complex", 9) == 0 && arg[9] == '\0')
        {
            *output = STRATEGY_COMPLEX;
            return (1); 
        }
        else if (ft_strncmp(arg, "--adaptive", 10) == 0 && arg[10] == '\0')
        {
            *output = STRATEGY_ADAPTIVE;
            return (1); 
        }
        return (-1);
    }
    return (0);
}

void dispatch_strategy(t_stack **a, t_stack **b, t_strategy s)
{
    if (s == STRATEGY_SIMPLE)
    {
        simple_sort(a, b);
        ft_putstr_fd("sort strategy: simple sort\n", 1);//for testing, remove later
    }
    else if (s == STRATEGY_MEDIUM)
    {
        medium_sort(a, b);
        ft_putstr_fd("sort strategy: medium sort\n", 1);//for testing, remove later
    }
    else if (s == STRATEGY_COMPLEX)
    {
        complex_sort(a, b);
        ft_putstr_fd("sort strategy: complex sort\n", 1);//for testing, remove later
    }
    else if (s == STRATEGY_ADAPTIVE)
        adaptive_sort(a, b);
}
// call in main: dispatch_strategy(&a, &b, strategy);
// t_strategy s = STRATEGY_ADAPTIVE; only override it if a flag is detected

void adaptive_sort(t_stack **a, t_stack **b)
{
	double disorder;

    disorder = check_disorder(*a);
    if (disorder < 0.2)
    {
        simple_sort(a, b);
        ft_putstr_fd("sort strategy: simple sort\n", 1);//for testing, remove later
    }
    else if (disorder < 0.5)
    {
        medium_sort(a, b);
        ft_putstr_fd("sort strategy: medium sort\n", 1);//for testing, remove later
    }
    else
    {
        complex_sort(a, b);
        ft_putstr_fd("sort strategy: complex sort\n", 1);//for testing, remove later
    }
}

// void adaptive_sort(t_stack **a, t_stack **b)
// {

// }