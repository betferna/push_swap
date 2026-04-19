	#include "push_swap.h"

int main (int argc, char **argvs)
{
	t_stack *a;
	t_stack *b;
	char **temp;

	if (argc < 2)
		return (0);
	a = NULL;
	b = NULL;
	// if (!(is_numb(argvs) && no_duplicate(argvs) && ft_atoil(argvs)))
	// 	return (NULL);
	if (argc == 2)
		temp = ft_split(argvs[1], ' ');
	else
		temp = argvs + 1;	
	a = init_stack(temp);
	if (!a)
	{
		if (argc == 2)
			free_temp(temp);
		return (0);
	}
	print_stack(a);
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
