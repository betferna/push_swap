#include "push_swap.h"

int ft_check_valid(int argc, char **argvs)
{
	int i;
	if (argc < 2)
		return (0);
	i = 1;
	while (i < argc)
    {
        if (!is_numb(argvs[i]))
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

t_stack *ft_parce(int argc, char **argvs, t_stack *a)
{
	char **temp;
	if (argc == 2)
	{
		temp = ft_split(argvs[1], ' ');
	}
	else
		temp = argvs + 1;	

	a = init_stack(temp);
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
	int count;

	ft_memset(count, 0, sizeof(count));
	if (ft_check_valid(argc, argvs))
	{
		a = NULL;
		b = NULL;
		a = ft_parce(argc, argvs, a);
//**** test ****/

		printf("Disorder = %f\n", comp_disorder(&a));
		// printf("Disorder 2 = %f\n", check_disorder(&a));	
		sa(&a, count);
		print_stack(a);
		sb(&b, count);
		print_stack(b);
		ss(&a, &b, count);
		print_stack(a);
		print_stack(b);
		pa(&a,&b, count);
		print_stack(a);
		print_stack(b);
		pb(&a,&b, count);
		print_stack(a);
		print_stack(b);
		ra(&a, count);
		print_stack(a);
		print_stack(b);
		rb(&b, count);
		print_stack(a);
		print_stack(b);
		rr(&a,&b, count);
		print_stack(a);
		print_stack(b);
		rra(&a,count);
		print_stack(a);
		print_stack(b);
		rrb(&b, count);
		print_stack(a);
		print_stack(b);
		rrr(&a,&b, count);
		print_stack(a);
		print_stack(b);
	}
	free_stack(&a);
	free_stack(&b);
	return (0);
}

