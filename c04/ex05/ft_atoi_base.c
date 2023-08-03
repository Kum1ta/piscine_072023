/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbernar <edbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:52:28 by edbernar          #+#    #+#             */
/*   Updated: 2023/07/16 16:04:04 by edbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	verification(char *str)
{
	int	i;
	int	j;

	i = -1;
	while (str[++i])
	{
		j = -1;
		while (++j < i)
		{
			if (str[i] == str[j])
				return (1);
		}
		if (str[i] == '+' || str[i] == '-' || (str[i] >= 7 && str[i] <= 13))
			return (1);
	}
	if (i <= 1)
		return (1);
	return (0);
}

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

int	ft_atoi_base(char *str, char *base)
{
	int		res;
	int		i;
	int		sign;

	i = 0;
	if (verification(base))
		return (0);
	while ((str[i] >= 7 && str[i] <= 13) || str[i] == ' ')
		i++;
	sign = 1;
	while (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	res = 0;
	while (str[i] && str_in_base(base, str[i]) != -1)
	{
		res = (res * ft_strl(base)) + str_in_base(base, str[i]);
		i++;
	}
	return (res * sign);
}
