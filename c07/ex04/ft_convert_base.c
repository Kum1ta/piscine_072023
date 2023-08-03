/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbernar <edbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:37:18 by edbernar          #+#    #+#             */
/*   Updated: 2023/07/20 21:21:59 by edbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

long int	ft_atoi_base(char *str, char *base, int *sign);

long int	ft_strlen(char *str)
{
	long int	i;

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
		if (str[i] == '+' || str[i] == '-' || (str[i] >= 9 && str[i] <= 13))
			return (1);
	}
	if (i <= 1)
		return (1);
	return (0);
}

char	*ft_putnbr_base(long int nbr, char *base, int sign)
{
	char		*res;
	long int	nb;
	int			i;

	nb = nbr;
	i = 0;
	while (nb || i == 0)
	{
		nb = nb / ft_strlen(base);
		i++;
	}
	res = malloc((i + 1) * sizeof(char));
	if (sign)
		res[0] = '-';
	else
		i--;
	res[i + 1] = 0;
	while (i >= sign)
	{
		res[i] = base[nbr % ft_strlen(base)];
		nbr = nbr / ft_strlen(base);
		i--;
	}
	return (res);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long int	nb;
	int			sign;

	sign = 0;
	if (verification(base_from) || verification(base_to))
		return (NULL);
	nb = ft_atoi_base(nbr, base_from, &sign);
	if (sign == 1 || nb == 0)
		sign = 0;
	else
		sign = 1;
	return (ft_putnbr_base(nb, base_to, sign));
}
