/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 18:40:31 by betferna          #+#    #+#             */
/*   Updated: 2026/05/09 12:22:18 by user             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putbase_fd(unsigned long long nbr, char *base, int fd)
{
	int		count;
	size_t	base_len;

	count = 0;
	base_len = ft_strlen(base);
	if (nbr >= base_len)
		count += ft_putbase_fd(nbr / base_len, base, fd);
	count += write(fd, &base[nbr % base_len], 1);
	return (count);
}
