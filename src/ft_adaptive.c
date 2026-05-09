#include "push_swap.h"

int p_flag(char *arg, t_opts *opts)
{
    if (!arg || (arg[0] != '-' && arg[1] != '-'))
        return (0);
    if (ft_strncmp(arg, "--simple", 9) == 0)
        opts->strategy = STRATEGY_SIMPLE;
    else if (ft_strncmp(arg, "--medium", 8) == 0)
        opts->strategy = STRATEGY_MEDIUM;
    else if (ft_strncmp(arg, "--complex", 9) == 0)
        opts->strategy = STRATEGY_COMPLEX;
    else if (ft_strncmp(arg, "--adaptive", 10) == 0)
        opts->strategy = STRATEGY_ADAPTIVE;
    else if (ft_strncmp(arg, "--bench", 7) == 0)
    {
        opts->bench = 1;
        // print_bench(**a,*opts, *count, opts);
    }
    else
        return (0);
    return (1);
}

// void dispatch_strategy(t_stack **a, t_stack **b, t_strategy s)
// {
//     if (s == STRATEGY_SIMPLE)
//     {
//         simple_sort(a, b, );
//         ft_putstr_fd("sort strategy: simple sort\n", 1);//for testing, remove later
//     }
//     else if (s == STRATEGY_MEDIUM)
//     {
//         medium_sort(a, b);
//         ft_putstr_fd("sort strategy: medium sort\n", 1);//for testing, remove later
//     }
//     else if (s == STRATEGY_COMPLEX)
//     {
//         complex_sort(a, b);
//         ft_putstr_fd("sort strategy: complex sort\n", 1);//for testing, remove later
//     }
//     else if (s == STRATEGY_ADAPTIVE)
//         // adaptive_sort(a, b);
// }
// call in main: dispatch_strategy(&a, &b, strategy);
// t_strategy s = STRATEGY_ADAPTIVE; only override it if a flag is detected

t_strategy adaptive_sort(t_stack **a, t_stack **b, t_counter *count)
{
	double disorder;

    disorder = comp_disorder(a);
    if (disorder < 0.2)
    {
        simple_sort(a, b, count);
        return (STRATEGY_SIMPLE);
    }
    else if (disorder < 0.5)
    {
        // medium_sort(a, b, count);
        return (STRATEGY_MEDIUM);
    }
    else
    {
        complex_sort(a, b, count);
        return (STRATEGY_COMPLEX);
    }
}

// void adaptive_sort(t_stack **a, t_stack **b)
// {

// }


// int parse_args(int argc, char **argvs, t_opts *opts)
// {
// 	int i;

// 	opts->strategy = STRATEGY_ADAPTIVE;
// 	opts->bench = 0;
// 	i = 1;
// 	while (argc > i && argvs[i][0] == '-' && argvs[i][1] == '-')
// 	{
// 		if (ft_strncmp(argvs[i], "--bench", 7) == 0 && argvs[i][7] == '\0')
// 			opts->bench = 1;
// 		else if (p_flag(argvs[i], &opts->strategy))
// 				return (1);
// 		else
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

// void print_bench(t_stack **a, t_opts *opts, t_counter *count, t_strategy *opts)
// {
//     if (!opts->bench)
//         return ;
//     fprintf(stderr, "[bench] disorder:  %.2f%%\n", comp_disorder(a) * 100);
//     if (opts->strategy == STRATEGY_ADAPTIVE)
//         fprintf(stderr, "[bench] strategy:  Adaptive / O(n√n)\n");
//     else
//         fprintf(stderr, "[bench] strategy:  Default / O(n2)\n");
//     fprintf(stderr, "[bench] total_ops: %d\n", count->total);
//     fprintf(stderr, "[bench] sa: %2d  sb: %2d  ss: %2d  pa: %2d  pb: %2d\n",
//             count->sa, count->sb, count->ss, count->pa, count->pb);
//     fprintf(stderr, "[bench] ra: %2d  rb: %2d  rr: %2d  rra: %2d  rrb: %2d  rrr: %2d\n",
//             count->ra, count->rb, count->rr, count->rra, count->rrb, count->rrr);
// }

/*
create functions:
1. returns chosen stragy name
2. returns complexity level
3. prints bench

*/


