
/* ****From header file:******

int		parse_args(int argc, char **arg, t_opts *opts);
double 	check_disorder(t_stack **stack);
// void	ft_lstadd_front(t_stack *lst, t_stack *new);
//void	ft_delone(t_stack *lst);
void	ft_delone(t_stack **lst);
// void	ft_lstadd_front(t_stack **lst, t_stack **new);
// int		all_numbers(char **argvs);
int 	is_flag(char *str);
//void 	ft_circular(t_stack **stack);
t_stack	*ft_lstlast(t_stack **lst);
void	ft_lstdellast(t_stack **lst);


***** Functions;

Pasring: 


// int parse_args(int argc, char **argvs, t_opts *opts)
// {
// 	int i;

// 	opts->strategy = STRATEGY_ADAPTIVE;
// 	opts->bench = 0;
// 	i = 1;
// 	while (argc > i && argvs[i][0] == '-' && argvs[i][1] == '-')
// 	{
// 		if (ft_strncmp(argvs[i], "--bench", 7) == 0 && argvs[i][7] == '\0')
// 			opts->bench = 1;
// 		else if (p_flag(argvs[i], &opts->strategy))
// 				return (1);
// 		else
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }


// int all_numbers(char **argvs)
// {
// 	int i;

// 	i = 0;
// 	while (*argvs[i])
// 	{
// 		if (!is_numb_flag(argvs[i]))
// 			return (0);
// 		i++;
// 	}
// 	return (1);		
// }

// void ft_push(t_stack **dst, t_stack **src)
// {
// 	t_stack *tailtmp;

// 	if (!dst || !src || !*src)
// 		return ;
// 	// while (tail->next != NULL)
// 	// 	tail = tail->next;
// 	tail = ft_lstlast(src);
// 	ft_lstadd_front(dst, &tail);
// 	ft_lstdellast(src);
// 	// ft_delone(src);
// }

t_stack	*ft_lstlast(t_stack **lst)
{
	t_stack *last = *lst;
	if (!lst || !*lst)
		return (*lst);
	while (last->next != NULL)
		last = last->next;
	return (last);
}


// void	ft_lstadd_front(t_stack **lst, t_stack **new)
// {
// 	if (!lst || !new || !*new)
// 		return ;
// 	(*new)->next = *lst;
// 	*lst = *new;
// }

// void	ft_lstadd_front(t_stack *lst, t_stack *new)
// {
// 	if (!lst || !new)
// 		return ;
// 	new->next = lst;
// 	lst = new;
// }
// void	ft_delone(t_stack *lst)
// {
// 	if (lst == NULL)
// 		return ;
// 	free(lst);
// }

// int is_flag(char *str)
// {
// 	if (!str)
// 		return (0);
// 	if (str[0] == '-' && str[1] == '-')
// 	{	
// 		return (1);
// 	}
// 	return (0);
// }

// void	ft_lstclear(t_stack **lst, void (*del)(void *))
// {
// 	t_list	*temp;

// 	if (lst == NULL)
// 		return ;
// 	while (*lst)
// 	{
// 		temp = (*lst)->next;
// 		del((*lst)->content);
// 		free(*lst);
// 		*lst = temp;
// 	}
// 	*lst = NULL;
// }




*/