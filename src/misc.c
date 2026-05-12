#include "push_swap.h"

double comp_disorder(t_stack **stack)
{
	int mistakes = 0;
	int total_pairs = 0;
	t_stack *i = *stack;
	t_stack *j;
	if (!stack || !*stack)
		return (0.0);
	while (i != NULL)
	{
		j = i->next;
		while (j != NULL)
		{
			if (i->value > j->value)
                mistakes++;
            total_pairs++;
            j = j->next;
		}
		i = i->next;
	}
	return ((double)mistakes / total_pairs);
}

int is_stack_stored(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void free_stack(t_stack **stack)
{
	t_stack *temp;
 
	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
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

int	ft_stacksize(t_stack *stack)
{
	int		size;
	t_stack	*temp;

	temp = stack;
	if (stack == NULL)
		return (0);
	size = 1;
	while (temp->next != NULL)
	{
		temp = temp->next;
		size++;
	}
	return (size);
}