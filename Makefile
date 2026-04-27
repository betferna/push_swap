NAME	= push_swap

LIBFT_DIR = ./libft
LIBFT	= $(LIBFT_DIR)/libft.a
INCLUDES	= -I ./libft

CC 	= cc
CFLAGS 	= -Wall -Wextra -Werror -I. $(INCLUDES)

SRC_DIR = src/
SRC_FILES = check_stack.c \
            ft_push.c \
            ft_revrot.c \
            ft_rotate.c \
            ft_swap.c \
            parcing.c \
            push_swap_utils.c \
            push_swap.c\
			comp_disorder.c\
			check_disorder.c

SRCS 	= $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS	= $(SRCS:.c=.o)

all	: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)


# $(NAME)	: $(LIBFT) $(OBJS)
# 	cp $(LIBFT) $(NAME)
# 	ar rcs $(NAME) $(OBJS)

$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean	:
	@rm -f $(OBJS)
	@make -C $(LIBFT_DIR) clean --no-print-directory

fclean	: clean 	
	@rm -f $(NAME) test_printf
	@make -C $(LIBFT_DIR) fclean --no-print-directory


re 	: fclean all

.PHONY 	: all clean fclean re
