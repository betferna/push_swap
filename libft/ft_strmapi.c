/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: betferna <betferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 18:42:19 by betferna          #+#    #+#             */
/*   Updated: 2026/03/21 18:42:21 by betferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*p;

	p = (char *)malloc(ft_strlen(s) + 1);
	if (s && p)
	{
		i = 0;
		while (s[i])
		{
			p[i] = f(i, s[i]);
			i++;
		}
		p[i] = '\0';
		return (p);
	}
	return (NULL);
}
