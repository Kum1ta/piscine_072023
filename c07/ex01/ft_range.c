/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbernar <edbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 23:07:42 by edbernar          #+#    #+#             */
/*   Updated: 2023/07/19 15:51:59 by edbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	i;

	if (min >= max)
		return (0);
	i = 0;
	tab = malloc((max - min) * sizeof(int));
	if (tab == NULL)
		return (0);
	while (min + i < max)
	{
		tab[i] = min + i;
		i++;
	}
	return (tab);
}
