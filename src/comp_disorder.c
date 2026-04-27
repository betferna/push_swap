#include "push_swap.h"

double comp_disorder(t_stack **stack)
{
	int mistakes = 0;
	int total_pairs = 0;
	t_stack *i = *stack;
	t_stack *j;
	if (!stack || !*stack)
		return (-1.0);
	while (i != NULL)
	{
		j = i->next;
		while (j != NULL)
		{
			mistakes += (i->value > j->value);
			j = j->next;			
            total_pairs += 1;
		}
		i = i->next;
	}
	return ((double)mistakes / total_pairs);
}