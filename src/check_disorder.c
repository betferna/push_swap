#include "push_swap.h"

double check_disorder(t_stack **stack)
{
    t_stack *n_node;
    t_stack *i_node;
    int total_pairs;
    int mistakes;

    total_pairs = 0;
    mistakes = 0;

    if (!stack || !*stack)
        return (-1.0);
    i_node = *stack;
    while (i_node != NULL)
    {
        n_node = i_node->next;
        while (n_node != NULL)
        {
        // if ((i_node)->value > n_node->value)
        //     mistakes++;
        mistakes += (i_node->value > n_node->value);
        n_node = n_node->next;
        total_pairs++;  
        }
    i_node = i_node->next;        
    }
    return ((double)mistakes / total_pairs);
}

