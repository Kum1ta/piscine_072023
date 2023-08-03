/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbernar <edbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 17:22:33 by edbernar          #+#    #+#             */
/*   Updated: 2023/07/24 16:58:17 by edbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int	main(int ac, char **av)
{
	int	fd;
	int	c;

	if (ac == 1)
	{
		write(1, "File name missing.\n", 19);
		return (0);
	}
	else if (ac > 2)
	{
		write(1, "Too many arguments.\n", 20);
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		write(1, "Cannot read file.\n", 18);
		return (0);
	}
	while (read(fd, &c, 1))
		write(1, &c, 1);
	close(fd);
	return (1);
}
