/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: betferna <betferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 12:15:48 by betferna          #+#    #+#             */
/*   Updated: 2026/04/27 11:25:54 by betferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
int *tny_sort(int arcs, char **argvs)
{
	if (arcs < 3)
	{
		THREE_		
	}
}


int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while ((s1[i] != '\0') || (s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
		{
			x = s1[i] - s2[i];
			return (x);
		}
		i++;
	}
	return (x);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write (1, &str[i], 1);
		i++;
	}
	write (1, "\n", 1);
}

int	ft_swap(int argc, char **argv)
{
	int		i;
	int		j;
	char	*temp;	

	if (argc > 1)
	{
		j = 1;
		while (j < argc - 1)
		{
			i = 1;
			while (i < argc - 1)
			{
				if ((ft_strcmp(argv[i], argv[i + 1]) > 0))
				{
					temp = argv[i];
					argv[i] = argv[i + 1];
					argv[i + 1] = temp;
				}
				i++;
			}
			j++;
		}
	}
	return (0);
}


int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	ft_swap(argc, argv);
	while (i < argc)
	{
		ft_putstr(argv[i]);
		i++;
	}
	return (0);
}
