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

void sort(t_stack **a, t_stack **b, t_strategy s)
{
    if (s == STRATEGY_SIMPLE)
    {
        simple_sort(a, b);
        write(1, "sort strategy: simple sort", 26);
    }
    else if (s == STRATEGY_MEDIUM)
    {
        medium_sort(a, b);
        write(1, "sort strategy: medium sort", 26);
    }
    else if (s == STRATEGY_COMPLEX)
    {
        complex_sort(a, b);
        write(1, "sort strategy: complex sort", 27);
    }
    else if (s == STRATEGY_ADAPTIVE)
    {
        adaptive_sort(a, b);
        write(1, "sort strategy: adaptive sort", 27);
    }
}

void adaptive_sort(t_stack **a, t_stack **b)
{
	double disorder;

    disorder = check_disorder(*a);
    if (disorder < 0.2)
    {
        simple_sort(a, b);
        write(1, "sort strategy: simple sort", 26);
    }
    else if (disorder < 0.5)
    {
        medium_sort(a, b);
        write(1, "sort strategy: medium sort", 26);
    }
    else
    {
        complex_sort(a, b);
        write(1, "sort strategy: complex sort", 27);
    }
}

// void adaptive_sort(t_stack **a, t_stack **b)
// {

// }