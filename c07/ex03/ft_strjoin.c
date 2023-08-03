/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbernar <edbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:01:38 by edbernar          #+#    #+#             */
/*   Updated: 2023/07/20 21:22:25 by edbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strjoin_part_two(char **strs, char *sep, int size, int size_mal)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	i = -1;
	j = 0;
	k = 0;
	str = malloc(size_mal * sizeof(char));
	if (str == NULL)
		return (0);
	while (strs[++i] && i < size)
	{
		j = -1;
		while (strs[i][++j])
			str[k++] = strs[i][j];
		j = -1;
		while (sep[++j] && i < size - 1)
			str[k++] = sep[j];
	}
	str[k] = 0;
	return (str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	i = -1;
	k = 0;
	if (!size)
	{
		str = malloc(1 * sizeof(char));
		return (str);
	}
	while (++i < size)
	{
		j = -1;
		while (strs[i][++j])
			k++;
	}
	i = 0;
	while (sep[i])
		i++;
	return (ft_strjoin_part_two(strs, sep, size, k + (i * (size - 1))));
}
