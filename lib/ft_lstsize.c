/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: betferna <betferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 18:39:12 by betferna          #+#    #+#             */
/*   Updated: 2026/03/21 20:03:18 by betferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*temp;

	temp = lst;
	if (lst == NULL)
		return (0);
	size = 1;
	while (temp->next != NULL)
	{
		temp = temp->next;
		size++;
	}
	return (size);
}
