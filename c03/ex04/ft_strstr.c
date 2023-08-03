/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbernar <edbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 23:42:15 by edbernar          #+#    #+#             */
/*   Updated: 2023/07/13 00:09:02 by edbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	unsigned int	i;
	unsigned int	j;

	i = -1;
	if (!to_find[0])
		return (str);
	while (str[++i])
	{
		j = 0;
		while (str[i + j] == to_find[j] && to_find[j])
			j++;
		if (!to_find[j])
			return (&str[i]);
	}
	return (0);
}
