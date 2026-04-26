#include "ft_printf.h"

int	ft_print_ptr(unsigned long long ptr)
{
	int	count;

	count = 0;
	if (!ptr)
		return (write(1, "(nil)", 5));
	count += write(1, "0x", 2);
	count += ft_putbase_fd(ptr, "0123456789abcdef", 1);
	return (count);
}

int	ft_print_int(int n)
{
	int	count;
	long	num;

	count = 0;
	if (n < 0)
	{
		count += write(1, "-", 1);
		num = ((long)n) * -1;
	}
	else
		num = (long)n;
	count += ft_putbase_fd((unsigned long long)num, "0123456789", 1);
	return (count);
}

int	ft_print_x(unsigned int n)
{
	int	count;
	long num = (long)n;

	count = 0;
	count += ft_putbase_fd(num, "0123456789abcdef", 1);
	return (count);
}

int	ft_print_upper_x(unsigned int n)
{
	int	count;

	count = 0;
	count += ft_putbase_fd(n, "0123456789ABCDEF", 1);
	return (count);
}