/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbernar <edbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:17:33 by edbernar          #+#    #+#             */
/*   Updated: 2023/07/13 22:07:05 by edbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_unprintable(unsigned char c)
{
	write(1, "\\", 1);
	write(1, &"0123456789abcdef"[c / 16], 1);
	write(1, &"0123456789abcdef"[c % 16], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!(str[i] >= 32 && str[i] <= 126))
			ft_print_unprintable((unsigned char)str[i]);
		else
			write(1, &str[i], 1);
	}
}
