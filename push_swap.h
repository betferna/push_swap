#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack {
	int		value;
	int		index;
	struct s_stack *next;
	struct s_stack *prev;
} t_stack;


# include <fcntl.h>
# include <limits.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

char	**ft_split(char const *s, char c);
void	ft_lstclear(t_stack **lst, void (*del)(void *));
t_stack *init_stack(char **argv);
void	ft_stack_add_back(t_stack **stack, t_stack *new);
t_stack	*ft_stack_new(int value);
int		ft_stacksize(t_stack *stack);
long long int	ft_atoil(const char *str);
void print_stack(t_stack *stack);
void free_stack(t_stack **stack);
void free_temp(char **temp);
t_stack *init_stack(char **temp);
void ft_circular(t_stack **stack);



# endif