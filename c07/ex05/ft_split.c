/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbernar <edbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:26:01 by edbernar          #+#    #+#             */
/*   Updated: 2023/07/19 19:05:14 by edbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_charset(char *charset, char c)
{
	int	i;

	i = -1;
	while (charset[++i])
	{
		if (charset[i] == c)
			return (1);
	}
	return (0);
}

int	ft_strl_sp(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] && !is_charset(charset, str[i]))
		i++;
	return (i);
}

char	**ft_split_part_two(char *str, char *charset, int tab[3], char **strf)
{
	int	len;

	strf = malloc((tab[0] + 1) * sizeof(char *));
	if (strf == NULL)
		return (0);
	while (++tab[1] < tab[0])
	{
		while (str[tab[2]] && is_charset(charset, str[tab[2]]))
			tab[2]++;
		len = (ft_strl_sp(&str[tab[2]], charset) + 1);
		strf[tab[1]] = malloc(len * sizeof(char));
		tab[3] = 0;
		while (str[tab[2]] && !is_charset(charset, str[tab[2]]))
			strf[tab[1]][tab[3]++] = str[tab[2]++];
		strf[tab[1]][tab[3]] = 0;
	}
	strf[tab[0]] = 0;
	return (strf);
}

char	**ft_split(char *str, char *charset)
{
	char	**strf;
	int		tab[4];

	tab[1] = 0;
	tab[0] = 0;
	strf = 0;
	while (str[tab[1]])
	{
		while (str[tab[1]] && is_charset(charset, str[tab[1]]))
			tab[1]++;
		if (str[tab[1]])
			tab[0]++;
		while (str[tab[1]] && !is_charset(charset, str[tab[1]]))
			tab[1]++;
	}
	tab[1] = -1;
	tab[2] = 0;
	return (ft_split_part_two(str, charset, tab, strf));
}
