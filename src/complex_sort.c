#include "push_swap.h"

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

int max_bits(int n)
{
int bits;
int max_bits;

bits = 0;
max_bits = n - 1;
while ((max_bits >> bits) != 0)
    bits++;
return (bits);
}

void complex_sort(t_stack **a, t_stack **b)
{
    int n;//#numbers
    int max_bits;// n-1 the total number or numbers in the stack. 
    int bit_position;
    int i;
    
    n = ft_stacksize(a);

        max_bits = max_bits((*a)->index == n)
    i = 0;
    bit_position = 0;
    (*a)->index = 0;
    while ()

    // if bit is 0 push to b (pb)
    // if bit is 1 rotate in A (ra)

}