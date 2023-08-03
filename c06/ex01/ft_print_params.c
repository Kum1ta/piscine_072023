/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbernar <edbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:11:22 by edbernar          #+#    #+#             */
/*   Updated: 2023/07/18 18:00:14 by edbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	(void)ac;
	while (av[++i])
	{
		write(1, av[i], ft_strlen(av[i]));
		write(1, "\n", 1);
	}
	return (0);
}
