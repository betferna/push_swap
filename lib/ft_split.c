/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: betferna <betferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 17:06:07 by betferna          #+#    #+#             */
/*   Updated: 2026/03/21 18:23:01 by betferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
