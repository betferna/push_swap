#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack {
	int		value;
	int		index;
	struct s_stack *next;
} t_stack;


# include <fcntl.h>
# include <limits.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
// # include "lib/libft.h"

char	**ft_split(char const *s, char c);
t_stack *init_stack(char **argv);
void	ft_stack_add_back(t_stack **stack, t_stack *new);
t_stack	*ft_stack_new(int value);
int		ft_stacksize(t_stack *stack);
long long int	ft_atoil(const char *str);
void 	print_stack(t_stack *stack);
void 	free_stack(t_stack **stack);
void 	free_temp(char **temp);
t_stack *init_stack(char **temp);
//void 	ft_circular(t_stack **stack);
void 	ft_swap(t_stack *a);
void 	ft_sa(t_stack *a);
void 	ft_sb(t_stack *b);
void 	ft_ss(t_stack *a, t_stack *b);
void	rotate(t_stack **stack);
void	ft_ra(t_stack **a);
void	ft_rb(t_stack **a);
void	ft_rr(t_stack **a, t_stack **b);
void	revrot(t_stack **stack);
void	ft_rra(t_stack **a);
void	ft_rrb(t_stack **b);
void	ft_rrr(t_stack **a, t_stack **b);
int		is_numb(char *str);
int		all_numbers(char **argvs);
int		no_duplicate(char **argvs);
int		range_check(char **str);
int		is_stack_stored(t_stack *stack);
int		ft_isdigit(int c);
void	ft_lstadd_front(t_stack *lst, t_stack *new);
void	ft_delone(t_stack *lst);
void 	ft_push(t_stack *dst, t_stack *src);










# endif