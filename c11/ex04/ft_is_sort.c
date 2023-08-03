/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbernar <edbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:33:04 by edbernar          #+#    #+#             */
/*   Updated: 2023/07/26 12:01:10 by edbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	count_one;
	int	count_two;
	int	i;

	i = 0;
	count_one = 0;
	count_two = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) < 0)
			count_one++;
		else if (f(tab[i], tab[i + 1]) > 0)
			count_two++;
		i++;
	}
	return (count_one == 0 || count_two == 0);
}
