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

int	ft_print_fd_int(int fd,int n)
{
	int	count;
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

int ft_print_fd_float(int fd, double n)
{
    int count = 0;

    if (n < 0) {
        count += write(fd, "-", 1);
        n = -n;
    }
    n += 0.005;
    unsigned long int_part = (unsigned long)n;
    count += ft_print_fd_int(fd, int_part);
    count += write(fd, ".", 1);
    double diff = n - (double)int_part;
    int decimals = (int)(diff * 100);
    if (decimals < 10)
        count += write(fd, "0", 1);
    count += ft_print_fd_int(fd, decimals);
    return (count);
}