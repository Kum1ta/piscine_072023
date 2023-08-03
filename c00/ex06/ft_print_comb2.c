/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbernar <edbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 00:03:32 by edbernar          #+#    #+#             */
/*   Updated: 2023/07/11 16:15:00 by edbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_nbr(int n[2])
{
	write(1, &(char){n[0] / 10 + 48}, 1);
	write(1, &(char){n[0] % 10 + 48}, 1);
	write(1, " ", 1);
	write(1, &(char){n[1] / 10 + 48}, 1);
	write(1, &(char){n[1] % 10 + 48}, 1);
	if (n[0] != 98)
		write(1, ", ", 2);
}

void	ft_print_comb2(void)
{
	int	n[2];

	n[0] = -1;
	while (++n[0] <= 98)
	{
		n[1] = n[0] + 1;
		while (n[1] <= 99)
		{
			print_nbr(n);
			n[1]++;
		}
	}
}