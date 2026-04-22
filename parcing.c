#include "push_swap.h"

void print_stack(t_stack *stack)
{
	t_stack *temp;

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
	t_stack	*first;

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
static void ft_stack_add_front(t_stack **stack, t_stack *newhead)
{
	if (!stack || !newhead)
		return ;
	newhead->next = *stack;
	if (*stack != NULL)
	*stack = newhead;
}

//new stakc node in back:
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

// void	ft_stack_add_back(t_stack **stack, t_stack *new)
// {
// 	t_stack	*last;

// 	if (!new || !stack)
// 		return ;
// 	if (*stack == NULL)
// 	{
// 		*stack = new;
// 		return ;
// 	}
// 	last = *stack;
// 	while (last->next)
// 		last = last->next;
// 	last->next = new;
// 	new->prev = last;
// }

// void ft_circular(t_stack **stack)
// {
// 	t_stack *first;
// 	t_stack *last;

// 	if (!stack || !*stack)
// 		return ;
// 	first = *stack;
// 	last = *stack;
// 	while (last->next != NULL)
// 		last = last->next;
// 	last->next = first;
// 	first->prev = last;
// }

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
	// ft_circular(&a);
	return (a);
}
