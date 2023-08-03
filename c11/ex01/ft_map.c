/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbernar <edbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 20:52:11 by edbernar          #+#    #+#             */
/*   Updated: 2023/07/29 21:24:33 by edbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*result;
	int	i;

	i = 0;
	result = malloc(length * sizeof(int));
	if (result == NULL)
		return (0);
	while (i < length)
	{
		result[i] = f(tab[i]);
		i++;
	}
	return (result);
}
