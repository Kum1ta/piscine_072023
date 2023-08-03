/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbernar <edbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 23:34:22 by edbernar          #+#    #+#             */
/*   Updated: 2023/07/17 13:14:36 by edbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	start_nb;

	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	start_nb = nb;
	while (power > 1)
	{
		nb = nb * start_nb;
		power--;
	}
	return (nb);
}
