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

/*
create functions:
1. returns chosen stragy name
2. returns complexity level
3. prints bench

*/


