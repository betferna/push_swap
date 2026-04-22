/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: betferna <betferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 11:17:53 by betferna          #+#    #+#             */
/*   Updated: 2026/03/21 18:37:03 by betferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*p;

	if (num != 0 && size > SIZE_MAX / num)
		return (NULL);
	p = malloc(num * size);
	if (!p)
		return (NULL);
	ft_bzero(p, (num * size));
	return (p);
}
