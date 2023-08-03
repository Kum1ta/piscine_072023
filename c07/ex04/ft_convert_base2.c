/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbernar <edbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:37:30 by edbernar          #+#    #+#             */
/*   Updated: 2023/07/20 18:09:03 by edbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

long int	ft_strlen(char *str);

int	str_in_base(char *base, char c)
{
	int	i;

	i = -1;
	while (base[++i])
	{
		if (base[i] == c)
			return (i);
	}
	return (-1);
}

long int	ft_atoi_base(char *str, char *base, int *sign)
{
	long int		res;
	int				i;

	i = 0;
	while ((str[i] >= 7 && str[i] <= 13) || str[i] == ' ')
		i++;
	*sign = 1;
	while (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			*sign *= -1;
		i++;
	}
	res = 0;
	while (str[i] && str_in_base(base, str[i]) != -1)
	{
		res = (res * (int)ft_strlen(base)) + str_in_base(base, str[i]);
		i++;
	}
	return (res);
}
