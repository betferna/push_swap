#include "push_swap.h"

int main (int argc, char **argvs)
{
	t_stack *a;
	t_stack *b;
	char **temp;
	int 	i;

	if (argc < 2)
		return (0);
	i = 1;
	while (i < argc)
    {
        if (!is_numb(argvs[i]))
        {
            write(2, "Error\n", 6);
            return (1);
        }
        i++;
    }
	if (!no_duplicate(argvs+1))
	{
            write(2, "Error\n", 6);
            return (1);
    }
	a = NULL;
	b = NULL;
	if (argc == 2)
		temp = ft_split(argvs[1], ' ');
	else
		temp = argvs + 1;	
	i = 1;

	// if (!(is_numb(temp) && no_duplicate(temp) && range_check(temp)))
	// {
	// 	if (argc == 2)
	// 		free_temp(temp);
	// 	write (2, "Error\n", 6);
	// 	return (1);
	// }
	// needs to be true and return error? 
	a = init_stack(temp);
	if (!a)
	{
		if (argc == 2)
			free_temp(temp);
		return (0);
	}
	// ft_sa(a);
	print_stack(a);
	// ft_pa(a, b);
	// print_stack(a);
	// if !ft_sorted
	// {
	// 	if arcs < 4
	// 		three_sort(&a, &b)
	// 	else if arcs < 7
	// 		small_sort(&a, &b)
	// 	else if arcs <	500
	// 		chunk_sort(&a, &b)
	// 	else
	// 		big_sort(&a, &b)
	// }
	free_stack(&a);
	if (argc == 2)
		free_temp(temp);
	return (0);
}
