	#include "push_swap.h"

// int is_num()

// int no_duplicate()

// int three_sort(a, b)

void print_stack(t_stack *stack)
{
	if (!stack)
		return ;
    while (stack)
    {
        printf("%d ", stack->value);
        stack = stack->next;
    }
    printf("\n");
}

void free_stack(t_stack **stack)
{
	t_stack	*temp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	*stack = NULL;
}

void free_temp(char **temp)
{
	int i;

	if (!temp)
		return ;
	i = 0;
	while (temp[i])
	{
		free(temp[i]);
		i++;
	}
	free(temp);
	temp = NULL;
}

t_stack *init_stack(char **temp)
{
	t_stack *a;
	int 	i;

	a = NULL;
	i = 0;
	if (!temp)
		return (NULL);
	while (temp[i])
	{
		ft_stack_add_back(&a, ft_stack_new((int)ft_atoil(temp[i])));
		i++;
	}
	return (a);
}

int main (int argc, char **argvs)
{
	t_stack *a;
	t_stack *b;
	char **temp;

	if (argc < 2)
		return (0);
	a = NULL;
	b = NULL;
	// if (!(is_numb(argvs) && no_duplicate(argvs) && ft_atoil(argv)))
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
