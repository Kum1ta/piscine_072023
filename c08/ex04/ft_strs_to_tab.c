/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbernar <edbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 01:00:30 by edbernar          #+#    #+#             */
/*   Updated: 2023/07/23 23:14:43 by edbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "./ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	dest = malloc((ft_strlen(src) + 1) * sizeof(char));
	if (dest == NULL)
		return (0);
	i = -1;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = 0;
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*tab;
	int			i;

	i = 0;
	tab = malloc((ac + 1) * sizeof(t_stock_str));
	if (tab == NULL)
		return (NULL);
	if (ac > 0)
	{
		while (i < ac)
		{
			tab[i].size = ft_strlen(av[i]);
			tab[i].str = av[i];
			tab[i].copy = ft_strdup(tab[i].str);
			i++;
		}
	}
	tab[i].str = 0;
	return (tab);
}
