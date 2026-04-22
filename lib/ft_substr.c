/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: betferna <betferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 18:43:41 by betferna          #+#    #+#             */
/*   Updated: 2026/03/21 18:43:43 by betferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > (ft_strlen(s)) - (size_t)start)
		len = ft_strlen(s) - (size_t)start;
	p = (char *)malloc(len + 1);
	if (!p)
		return (NULL);
	p = ft_memcpy(p, s + start, len);
	p[len] = '\0';
	return (p);
}
