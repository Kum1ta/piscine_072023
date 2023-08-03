/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbernar <edbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 11:58:30 by edbernar          #+#    #+#             */
/*   Updated: 2023/07/30 22:47:48 by edbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int	i;
	int	j;

	i = 1;
	while (tab[i])
	{
		j = i;
		while (j > 0 && cmp(tab[j - 1], tab[j]) > 0)
		{
			ft_swap(tab + j, tab + j - 1);
			j--;
		}
		i++;
	}
}
