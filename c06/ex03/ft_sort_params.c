/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbernar <edbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:27:59 by edbernar          #+#    #+#             */
/*   Updated: 2023/07/18 17:14:38 by edbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	main(int ac, char **av)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	while (++i < ac)
	{
		j = 0;
		while (++j < i)
		{
			if (ft_strcmp(av[j], av[i]) > 0)
			{
				tmp = av[j];
				av[j] = av[i];
				av[i] = tmp;
			}
		}
	}
	i = 0;
	while (av[++i])
	{
		write(1, av[i], ft_strlen(av[i]));
		write(1, "\n", 1);
	}
}
