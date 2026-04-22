/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: betferna <betferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 18:39:24 by betferna          #+#    #+#             */
/*   Updated: 2026/03/21 18:44:30 by betferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *buffer, int c, size_t count)
{
	unsigned char	*p;
	unsigned char	ch;
	size_t			i;

	p = (unsigned char *)buffer;
	ch = (unsigned char)c;
	i = 0;
	while (i < count)
	{
		if (p[i] == ch)
			return ((void *)&p[i]);
		i++;
	}
	return (NULL);
}
