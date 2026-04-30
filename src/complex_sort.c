#include "push_swap.h"

void complex_sort(t_stack **a, t_stack **b)
{
    (*a)->index = 0;
    int n;
    int max_bits;
    int bit_position;
    
    n = 0;
    bit_position = 0;
    while (*a != NULL)
    {
        (*a)->next->index += 1;
        n++;
    }
    max_bits = n-1;
    while 

}