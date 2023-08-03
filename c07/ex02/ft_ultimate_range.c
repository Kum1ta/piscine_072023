/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbernar <edbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 23:20:36 by edbernar          #+#    #+#             */
/*   Updated: 2023/07/19 18:58:09 by edbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	if (min >= max)
	{
		(*range) = 0;
		return (0);
	}
	i = 0;
	*range = malloc((max - min) * sizeof(int));
	if (*range == NULL)
		return (0);
	while (min + i < max)
	{
		(*range)[i] = min + i;
		i++;
	}
	return (i);
}
