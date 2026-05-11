#include "push_swap.h"

int ft_check_valid(int argc, char **argvs)
{
	int i;

	i = 1;
	while (i < argc)
    {
        if (!is_numb_flag(argvs[i]))
        {
            write(2, "Error\n", 6);
            return (0);
        }
        i++;
    }
	if (!no_duplicate(argvs+1))
	{
            write(2, "Error\n", 6);
            return (0);
    }
	return (1);
}

t_stack *ft_parse(int argc, char **argvs, t_stack *a, t_opts *opts)
{
	char **temp;
	if (argc == 2)
	{
		temp = ft_split(argvs[1], ' ');
	}
	else
		temp = argvs + 1;	

	a = init_stack(temp, opts);
	if (!a)
	{
		if (argc == 2)
			free_temp(temp);
		write(2, "Error\n", 6);
		return (NULL);
	}
	if (argc == 2)
		free_temp(temp);
	return (a);
}

int main (int argc, char **argvs)
{
	t_stack *a;
	t_stack *b;
	t_counter count;
	t_opts opts;
	double disorder;

	// count = malloc(sizeof(t_counter));
	// if (!count)
	// 	return (1);
	// opts = malloc(sizeof(t_opts));
	// if (!opts)
	// 	return (1);
	if (argc <2)
		return (0);
	ft_memset(&count, 0, sizeof(t_counter));
	opts.strategy = STRATEGY_ADAPTIVE;
	opts.bench = 0;
	a = NULL;
	b = NULL;
	if (!ft_check_valid(argc, argvs))
		return (1);
	a = ft_parse(argc, argvs, a, &opts);
	if (!a)
		return (1);
	disorder =  comp_disorder(&a);
		// ft_printf("Disorder = %i %% \n", disorder);
		dispatch_strategy(&a, &b, &opts, &count);
//**** test ****/

		// printf("Disorder 2 = %f\n", check_disorder(&a));	
		// sa(&a, count);
		// print_stack(a);
		// sb(&b, count);
		// print_stack(b);
		// ss(&a, &b, count);
		// print_stack(a);
		// print_stack(b);
		// pa(&a,&b, count);
		// print_stack(a);
		// print_stack(b);
		// pb(&a,&b, count);
		// print_stack(a);
		// print_stack(b);
		// ra(&a, count);
		// print_stack(a);
		// print_stack(b);
		// rb(&b, count);
		// print_stack(a);
		// print_stack(b);
		// rr(&a,&b, count);
		// print_stack(a);
		// print_stack(b);
		// rra(&a,count);
		// print_stack(a);
		// print_stack(b);
		// rrb(&b, count);
		// print_stack(a);
		// print_stack(b);
		// rrr(&a,&b, count);
		// print_stack(a);
		// print_stack(b);

		// print_stack(a);
		print_bench(&opts,&count,disorder);
		// complex_sort(&a, &b, count);
		// print_stack(a);
		// simple_sort(&a,&b, count);
		// print_stack(a);
		// print_stack(b);

	free_stack(&a);
	free_stack(&b);
	return (0);
}

