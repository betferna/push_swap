#include "push_swap.h"

int comp_disorder(t_stack **stack)
{
	int mistakes = 0;
	int total_pairs = 0;
	t_stack *i = *stack;
	t_stack *j;
	if (!stack || !*stack)
		return (-1);
	while (i->next != NULL)
	{
		j = i->next;
		while (j->next != NULL)
		{
			total_pairs += 1;
			if (i->value > j->value)
				mistakes += 1;
			j = j->next;
		}
		i = i->next;
	}
	return (mistakes / total_pairs);
}