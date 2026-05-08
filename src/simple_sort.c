/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 12:15:48 by betferna          #+#    #+#             */
/*   Updated: 2026/05/08 22:16:45 by user             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 12:15:48 by betferna          #+#    #+#             */
/*   Updated: 2026/05/08 22:12:11 by user             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/*
** Comprueba si 'comp' es el valor más alto del stack actual.
** Pasamos el stack como puntero simple para no modificar el original.
*/
int is_higher(t_stack *comp, t_stack *head)
{
	if (!comp || !head)
		return (0);
	while (head)
	{
		if (head->value > comp->value)
			return (0);
		head = head->next;
	}
	return (1);
}

/*
** Ordena exactamente 3 elementos en el Stack A.
** Máximo 2 o 3 movimientos.
*/
void three_sort(t_stack **stack, t_counter *count)
{
	if (!stack || !*stack || ft_lstsize(*stack) != 3)
		return ;

	// 1. Si el primero es el más alto, lo mandamos al fondo.
	if (is_higher(*stack, *stack))
		ra(stack, count);
	// 2. Si el segundo es el más alto, hacemos rra (el de abajo sube al top).
	else if (is_higher((*stack)->next, *stack))
		rra(stack, count);

	// 3. Al final, solo queda comprobar si los dos de arriba están en orden.
	if ((*stack)->value > (*stack)->next->value)
		sa(stack, count);
}

/*
** Gestor de algoritmos pequeños.
*/
void simple_sort(t_stack **a, t_stack **b, t_counter *count)
{
	int size;

	if (!a || !*a)
		return ;
	size = ft_lstsize(*a);
	if (size == 2)
	{
		if ((*a)->value > (*a)->next->value)
			sa(a, count);
	}
	else if (size == 3)
		three_sort(a, count);
	else if (size <= 5)
	    five_sort(a, b, count);
}

void five_sort(t_stack **a, t_stack **b, t_counter *count)
{
	if (!a || !b || !count)
		return ;
}