/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: betferna <betferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 18:43:23 by betferna          #+#    #+#             */
/*   Updated: 2026/03/21 18:43:25 by betferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isset(char c, char const *set)
{
	int	start;

	start = 0;
	while (set[start])
	{
		if (set[start] == c)
			return (1);
		start++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*s;

	start = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[start] && ft_isset(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_isset(s1[end - 1], set))
		end--;
	s = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!s)
		return (NULL);
	i = 0;
	while (start < end)
	{
		s[i] = s1[start];
		start++;
		i++;
	}
	s[i] = '\0';
	return (s);
}
