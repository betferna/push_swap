#ifndef	FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "./libft/libft.h"

int	ft_printf(const char *format, ...);
int	ft_print_ptr(unsigned long long ptr);
int	ft_print_int(int n);
int	ft_print_x(unsigned int n);
int	ft_print_upper_x(unsigned int n);

#endif
