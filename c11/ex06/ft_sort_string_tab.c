/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbernar <edbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 11:44:00 by edbernar          #+#    #+#             */
/*   Updated: 2023/07/26 12:02:39 by edbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_sort_string_tab(char **tab)
{
	char	*tmp;
	int		i;
	int		j;

	i = -1;
	while (tab[++i])
	{
		j = -1;
		while (++j < i)
		{
			if (ft_strcmp(tab[j], tab[i]) > 0)
			{
				tmp = tab[j];
				tab[j] = tab[i];
				tab[i] = tmp;
			}
		}
	}
}
