#include "push_swap.h"

int parse_args(int argc, char **argvs, t_opts *opts)
{
	int i;

	opts->strategy = STRATEGY_ADAPTIVE;
	opts->bench = 0;
	i = 1;
	while (argc > i && argvs[i][0] == '-' && argvs[i][1] == '-')
	{
		if (ft_strncmp(argvs[i], "--bench", 7) == 0 && argvs[i][7] == '\0')
			opts->bench = 1;
		else if (p_flag(argvs[i], &opts->strategy))
				return (1);
		else
			return (0);
		i++;
	}
	return (1);
}

void print_bench(t_stack **a, t_opts *opts, t_counter *count)
{
    if (!opts->bench)
        return ;
    fprintf(stderr, "[bench] disorder:  %.2f%%\n", comp_disorder(a) * 100);
    if (opts->strategy == STRATEGY_ADAPTIVE)
        fprintf(stderr, "[bench] strategy:  Adaptive / O(n√n)\n");
    else
        fprintf(stderr, "[bench] strategy:  Default / O(n2)\n");
    fprintf(stderr, "[bench] total_ops: %d\n", count->total);
    fprintf(stderr, "[bench] sa: %2d  sb: %2d  ss: %2d  pa: %2d  pb: %2d\n",
            count->sa, count->sb, count->ss, count->pa, count->pb);
    fprintf(stderr, "[bench] ra: %2d  rb: %2d  rr: %2d  rra: %2d  rrb: %2d  rrr: %2d\n",
            count->ra, count->rb, count->rr, count->rra, count->rrb, count->rrr);
}

/*
create functions:
1. returns chosen stragy name
2. returns complexity level
3. prints bench

*/


