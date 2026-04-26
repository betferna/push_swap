NAME	= libftprintf.a

LIBFT_DIR = ../libft

LIBFT	= $(LIBFT_DIR)/libft.a
	
SRCS	= ft_printf.c ft_printf_utils.c

OBJS 	= $(SRCS:.c=.o)

CC 	= cc

INCLUDES	= -I $(LIBFT_DIR)

CFLAGS 	= -Wall -Wextra -Werror -I. $(INCLUDES)

all	: $(NAME)

$(NAME)	: $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

$(LIBFT):
	@make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

test: all
	$(CC) $(CFLAGS) main.c $(NAME) -o test_printf
	./test_printf

clean	:
	@rm -f $(OBJS)
	@make -C $(LIBFT_DIR) clean --no-print-directory

fclean	: clean 	
	@rm -f $(NAME) test_printf
	@make -C $(LIBFT_DIR) fclean --no-print-directory

re 	: fclean all

.PHONY 	: all clean fclean re
