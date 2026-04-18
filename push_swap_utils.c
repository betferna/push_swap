#include "push_swap.h"

t_stack	*ft_stack_new(int value)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	ft_stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!new || !stack)
		return ;
	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = new;
	new->prev = last;
}

int	ft_stacksize(t_stack *stack)
{
	int		size;
	t_stack	*temp;

	temp = stack;
	if (stack == NULL)
		return (0);
	size = 1;
	while (temp->next != NULL)
	{
		temp = temp->next;
		size++;
	}
	return (size);
}

// t_stack *init_stack(char **argv)
// {
// 	t_stack **a;
// 	int 	i;

// 	if (!argv)
// 		return (NULL);
// 	i = 0;
// 	*a = ft_stack_new(ft_atoil(argv[i]));
// 	while (argv[i++])
// 		ft_stack_add_back(a, ft_stack_new(ft_atoil(argv[i])));
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

static int	count_words(const char *str, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (*str != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*str == c)
			in_word = 0;
		str++;
	}
	return (count);
}

static int	word_len(char const *str, char chars)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != chars)
		i++;
	return (i);
}

static void	*malloc_arr(char **arr, int j, int len)
{
	arr[j] = malloc(len + 1);
	if (!arr[j])
	{
		while (j >= 0)
			free(arr[j--]);
		free(arr);
		return (NULL);
	}
	return (arr[j]);
}

static int	locate_st(char *arr, const char *s, int i, int len)
{
	int	k;

	k = 0;
	while (k < len)
		arr[k++] = s[i++];
	arr[k] = '\0';
	return (i);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**arr;

	arr = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!arr)
		return (NULL);
	i = 0;
	j = 0;
	while (j < count_words(s, c))
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			if ((malloc_arr(arr, j, word_len(s + i, c))))
				i = locate_st(arr[j], s, i, word_len(s + i, c));
			j++;
		}
	}
	arr[j] = NULL;
	return (arr);
}


long long int	ft_atoil(const char *str)
{
	size_t				i;
	int					min;
	unsigned long long	res;

	i = 0;
	min = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			min *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + str[i] - '0';
		if (res > (unsigned long long)LLONG_MAX && min == 1)
			return (-1);
		if (res > (unsigned long long)LLONG_MAX + 1 && min == -1)
			return (0);
		i++;
	}
	return ((long long int)min * res);
}
