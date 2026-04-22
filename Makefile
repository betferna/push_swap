NAME	= push_swap
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
            push_swap.c

SRCS 	= $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS	= $(SRCS:.c=.o)

all	: $(NAME)

$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean	:
	@rm -f $(OBJS)

fclean	: clean 	
	@rm -f $(NAME)

re 	: fclean all

.PHONY 	: all clean fclean re
