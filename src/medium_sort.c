#include "push_swap.h"

void ft_index_stack(t_stack *a)
{
    t_stack *current;
    t_stack *compare;
    int index;

    current = a;
    while (current != NULL)
    {
        index = 0;
        compare = a;
        while (compare != NULL)
        {
            if (compare->value < current->value)
                index++;
            compare = compare->next;
        }
        current->index = index;
        current = current->next;
    }
}

void medium_sort(t_stack **a, t_stack **b, t_counter *count)
{
	int counter;
	int n;
	int chunk;

	counter = 0;
	chunk = 0;
	if (!a || !*a)
		return ;
	n = ft_lstsize(*a);
	ft_index_stack(*a);
	if (n <= 100)
		chunk = 20;
	else if (n <= 500)
		chunk = 35;
	pass_to_b(a,b,count,counter,chunk);
	order_list(a,b,count);
}

void pass_to_b(t_stack **a, t_stack **b, t_counter *count, int counter, int chunk)
{
	while (*a)
	{
		if ((*a)->index <= counter)
		{
			pb(a,b,count);
			rb(b,count);
			counter++;
		}
		else if ((*a)->index <= counter + chunk)
		{
			pb(a,b,count);
			counter++;
		}
		else
		{
			ra(a,count);
		}
	}
}

void order_list(t_stack **a, t_stack **b, t_counter *count)
{
	int max;
	int pos;
	int size;
	while (*b)
	{
		size = ft_lstsize(*b);
		max = size - 1;
		pos = ft_position(*b, max);
		if (pos >=0 && pos <= size /2)
		{
			while ((*b)->index != max)
				rb(b, count);
		}
		else {
			while ((*b)->index != max)
				rrb(b,count);
		}
		pa(a,b,count);
	}
}

int ft_position(t_stack *stack, int index)
{
	int pos;

	pos = 0;
	if (!stack)
		return (-1);
	while (stack != NULL)
	{
		if (stack->index == index)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (-1);
}