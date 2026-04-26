/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: betferna <betferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 18:43:05 by betferna          #+#    #+#             */
/*   Updated: 2026/03/21 18:43:07 by betferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		len;
	char	ch;

	ch = (char)c;
	if (!str)
		return (NULL);
	len = ft_strlen(str);
	while (len >= 0)
	{
		if (str[len] == ch)
			return ((char *)&str[len]);
		len--;
	}
	return (NULL);
}
