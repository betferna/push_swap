#include "libft.h"

int	ft_print_fd_char(int fd, int n)
{
	return (write(fd, &n, 1));
}

int	ft_print_fd_str(int fd, char *str)
{
	if (!str)
		str = "(null)";
	ft_putstr_fd(str, fd);
	return (ft_strlen(str));
}

static int	check_format_fd(int fd, char specifier, va_list args)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_print_fd_char(fd, va_arg(args, int));
	else if (specifier == 's')
		count += ft_print_fd_str(fd, va_arg(args, char *));
	else if (specifier == 'p')
		count += ft_print_fd_ptr(fd, va_arg(args, unsigned long long));
	else if (specifier == 'd' || specifier == 'i')
		count += ft_print_fd_int(fd, va_arg(args, int));
	else if (specifier == 'u')
		count += ft_putbase_fd(va_arg(args, unsigned int), "0123456789", fd);
	else if (specifier == 'f')
		count += ft_print_fd_float(fd, va_arg(args, double));
	else if (specifier == '%')
		count += write(fd, "%", 1);
	return (count);
}

int	ft_printf_fd(int fd, const char *format, ...)
{
	va_list	args;
	int		i;
	int		total_len;

	if (!format)
		return (-1);
	va_start(args, format);
	i = 0;
	total_len = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			total_len += check_format_fd(fd,format[i + 1], args);
			i++;
		}
		else
			total_len += write(fd, &format[i], 1);
		i++;
	}
	va_end(args);
	return (total_len);
}
