/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbernar <edbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:13:44 by edbernar          #+#    #+#             */
/*   Updated: 2023/07/11 11:44:36 by edbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	write(1, &(char){nb % 10 + 48}, 1);
}

void	print_nbr(int nbr[10], int n)
{
	int	i;

	while (++nbr[n - 1] < 10)
	{
		i = -1;
		while (++i < n)
			ft_putnbr(nbr[i]);
		if (nbr[0] != 10 - n)
			write(1, ", ", 2);
	}
}

void	ft_print_combn(int n)
{
	int	nbr[11];

	nbr[10] = -1;
	while (++nbr[10] < 10)
		nbr[nbr[10]] = nbr[10];
	while (nbr[0] <= 10 - n)
	{
		nbr[n - 1]--;
		print_nbr(nbr, n);
		if (n == 1)
			return ;
		nbr[10] = n;
		while (--nbr[10] > -1)
			if (nbr[nbr[10]] > 9)
				nbr[nbr[10] - 1]++;
		while (++nbr[10] < n)
		{
			if (nbr[nbr[10]] > 9)
			{
				nbr[10]--;
				while (++nbr[10] - 1 < n)
					nbr[nbr[10]] = nbr[nbr[10] - 1] + 1;
			}
		}
	}
}
