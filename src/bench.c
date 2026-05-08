#include "push_swap.h"

int parse_args(int argc, char *argvs, t_opts *opts)
{
	int i;

	opts->strategy = STRATEGY_ADAPTIVE;
	opts->bench = 0;
	i = i;
	while (argc > 1 && argvs[0] == '-' && argvs[1] == '-')
	{
		if (ft_strncmp(argvs, "--bench", 7) == 0 && argvs[7] == '\0')
			opts->bench = 1;
		else if (p_flag((argvs[i], &opts->strategy) == 1))
				return ;
		else
			return (0);
	}
	return (1);
}

/*
create functions:
1. returns chosen stragy name
2. returns complexity level
3. prints bench

*/


