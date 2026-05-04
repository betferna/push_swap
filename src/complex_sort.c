#include "push_swap.h"

void complex_sort(t_stack **a, t_stack **b)
{
    int n;//#numbers
    int max_bits;// n-1 the total number or numbers in the stack. 
    int bit_position;
    int i;
    
    n = 0;
    i = 0;
    bit_position = 0;
    (*a)->index = 0;
    max_bits = n-1;
    while ()

}

void assign_index(t_stack **a)
{
    int count;
    t_stack *node_i;
    t_stack *node_j;

    if (!a || !*a)
        return ;
    node_i = *a;
    while (node_i != NULL)
    {
        node_j = *a;
        count = 0;
        while (node_j != NULL)
        {
            if (node_j->value < node_i->value)
                count++; 
            node_j = node_j->next;
        }
    node_i->index = count;
    node_i = node_i->next;
    }
}