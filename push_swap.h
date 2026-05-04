#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack {
	int		value;
	int		index;
	struct s_stack *next;
} t_stack;

typedef enum s_strategy
{
	STRATEGY_ADAPTIVE,
	STRATEGY_SIMPLE,
	STRATEGY_MEDIUM,
	STRATEGY_COMPLEX
}   t_strategy;

typedef struct s_counter
{
	int sa;
	int sb;
	int ss;
	int pa;
	int pb;
	int pb;
	int ra;
	int rb;
	int rr;
	int rra;
	int rrb;
	int rrr;
	int total;
}   t_counter

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
void 	ft_swap(t_stack **stack);
void 	sa(t_stack **a, t_counter *count);
void 	sb(t_stack **b, t_counter *count);
void 	ss(t_stack **a, t_stack **b, t_counter *count);
void	pa(t_stack **a, t_stack **b, t_counter *count);
void	pb(t_stack **a, t_stack **b, t_counter *count);
void	rotate(t_stack **stack);
void	ra(t_stack **a, t_counter *count);
void	rb(t_stack **a, t_counter *count);
void	rr(t_stack **a, t_stack **b, t_counter *count);
void	revrot(t_stack **stack, t_counter *count);
void	rra(t_stack **a, t_counter *count);
void	rrb(t_stack **b, t_counter *count);
void	rrr(t_stack **a, t_stack **b, t_counter *count);
void 	ft_push(t_stack **dst, t_stack **src);
int		is_numb(char *str);
int		all_numbers(char **argvs);
int		no_duplicate(char **argvs);
int		range_check(char **str);
int		is_stack_stored(t_stack *stack);
int		ft_isdigit(int c);
void	ft_lstadd_front(t_stack **lst, t_stack **new);
void	ft_delone(t_stack **lst);
// void	ft_lstadd_front(t_stack *lst, t_stack *new);
//void	ft_delone(t_stack *lst);
void	ft_push(t_stack **dst, t_stack **src);
void	ft_revrot(t_stack **stack);
void 	ft_stack_add_front(t_stack **stack, t_stack *tail);
t_stack	*ft_lstlast(t_stack **lst);
void	ft_lstdellast(t_stack **lst);
double 	comp_disorder(t_stack **stack);
double 	check_disorder(t_stack **stack);








# endif