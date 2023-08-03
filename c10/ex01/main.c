/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbernar <edbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 18:12:03 by edbernar          #+#    #+#             */
/*   Updated: 2023/07/27 00:28:09 by edbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <libgen.h>

void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
}

void	print_error(char *prog_name, char *file)
{
	ft_putstr(prog_name);
	ft_putstr(": ");
	ft_putstr(file);
	ft_putstr(": ");
	ft_putstr(strerror(errno));
	ft_putstr("\n");
}

int	main(int ac, char **av)
{
	char	c;
	int		i;
	int		fd;

	if (ac == 1)
	{
		while (read(0, &c, 1))
			write(1, &c, 1);
		return (0);
	}
	i = 0;
	while (++i < ac)
	{
		fd = open(av[i], O_RDWR);
		if (fd == -1)
		{
			print_error(av[0], av[i]);
			continue ;
		}
		else
			while (read(fd, &c, 1))
				write(1, &c, 1);
		close(fd);
	}
	return (0);
}
