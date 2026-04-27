#include "push_swap.h"

void print_stack(t_stack *stack)
{
	if (!stack)
		return ;
    while (stack)
    {
        printf("%d\n", stack->value);
        stack = stack->next;
    }
    printf("\n");
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

t_stack	*ft_stack_new(int value)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->next = NULL;
	return (node);
}

//new stack node in front:
void ft_stack_add_front(t_stack **stack, t_stack *newhead)
{
	if (!stack || !newhead)
		return ;
	newhead->next = *stack;
	*stack = newhead;
}

void	ft_stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!new || !stack)
		return ;
	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = new;
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
