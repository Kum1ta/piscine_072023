/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbernar <edbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:16:50 by edbernar          #+#    #+#             */
/*   Updated: 2023/07/16 16:04:11 by edbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
		if (str[i] == '+' || str[i] == '-')
			return (1);
	}
	if (i <= 1)
		return (1);
	return (0);
}

void	ft_putnbr_base_rec(long int nbr, char *base)
{
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= ft_strlen(base))
		ft_putnbr_base_rec(nbr / ft_strlen(base), base);
	write(1, &base[nbr % ft_strlen(base)], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long int	nb;

	nb = (long int)nbr;
	if (verification(base))
		return ;
	ft_putnbr_base_rec(nb, base);
}
