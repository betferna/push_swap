#include "ft_printf.h"

int	ft_print_char(int n)
{
	return (write(1, &n, 1));
}

int	ft_print_str(char *str)
{
	if (!str)
		str = "(null)";
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

static int	check_format(char specifier, va_list args)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_print_char(va_arg(args, int));
	else if (specifier == 's')
		count += ft_print_str(va_arg(args, char *));
	else if (specifier == 'p')
		count += ft_print_ptr(va_arg(args, unsigned long long));
	else if (specifier == 'd' || specifier == 'i')
		count += ft_print_int(va_arg(args, int));
	else if (specifier == 'u')
		count += ft_putbase_fd(va_arg(args, unsigned int), "0123456789", 1);
	else if (specifier == 'x')
		count += ft_print_x(va_arg(args, unsigned int));
	else if (specifier == 'X')
		count += ft_print_upper_x(va_arg(args, unsigned int));
	else if (specifier == '%')
		count += write(1, "%", 1);
	return (count);
}

int	ft_printf(const char *format, ...)
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
			total_len += check_format(format[i + 1], args);
			i++;
		}
		else
			total_len += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (total_len);
}
