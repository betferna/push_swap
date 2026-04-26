/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: betferna <betferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 12:15:40 by user              #+#    #+#             */
/*   Updated: 2026/03/21 18:37:20 by betferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	if (n == 0)
		i = 1;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*p;
	long	num;

	num = (long)n;
	len = ft_len(num);
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	if (num == 0)
		p[0] = '0';
	if (num < 0)
	{
		p[0] = '-';
		num = -num;
	}
	p[len] = '\0';
	len--;
	while (num > 0)
	{
		p[len] = (num % 10) + '0';
		num /= 10;
		len--;
	}
	return (p);
}
