/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 18:41:12 by betferna          #+#    #+#             */
/*   Updated: 2026/05/17 14:34:32 by user             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_fd_ptr(int fd, unsigned long long ptr)
{
	int	count;

	count = 0;
	if (!ptr)
		return (write(fd, "(nil)", 5));
	count += write(fd, "0x", 2);
	count += ft_putbase_fd(ptr, "0123456789abcdef", fd);
	return (count);
}

int	ft_print_fd_int(int fd, int n)
{
	int		count;
	long	num;

	count = 0;
	if (n < 0)
	{
		count += write(fd, "-", 1);
		num = ((long)n) * -1;
	}
	else
		num = (long)n;
	count += ft_putbase_fd((unsigned long long)num, "0123456789", fd);
	return (count);
}

int	ft_print_fd_float(int fd, double n)
{
	int				count;
	unsigned long	int_part;
	double			diff;
	int				decimals;

	count = 0;
	if (n < 0)
	{
		count += write(fd, "-", 1);
		n = -n;
	}
	n += 0.005;
	int_part = (unsigned long)n;
	count += ft_print_fd_int(fd, int_part);
	count += write(fd, ".", 1);
	diff = n - (double)int_part;
	decimals = (int)(diff * 100);
	if (decimals < 10)
		count += write(fd, "0", 1);
	count += ft_print_fd_int(fd, decimals);
	return (count);
}
