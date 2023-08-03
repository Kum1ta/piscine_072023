/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbernar <edbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:57:32 by edbernar          #+#    #+#             */
/*   Updated: 2023/08/01 22:57:39 by edbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <libgen.h>

int		write_in_terminal(int size, int ac, int j);
int		ft_strcmp(char *s1, char *s2);
void	ft_putstr(char *str);
int		ft_atoi(char *str);

int	print_error(char *prog_name, char *file, int i, int size)
{
	if (i == 0)
	{
		ft_putstr(prog_name);
		ft_putstr(": cannot open '");
		ft_putstr(file);
		ft_putstr("' for reading: ");
		ft_putstr(strerror(errno));
		ft_putstr("\n");
	}
	else if (i == 1 && size == -1)
	{
		ft_putstr(prog_name);
		ft_putstr(": invalid number of bytes: ‘");
		ft_putstr(file);
		ft_putstr("’\n");
		return (1);
	}
	else if (i == 2)
	{
		ft_putstr(prog_name);
		ft_putstr(": option requires an argument -- 'c'\n");
	}
	return (0);
}

void	write_text(char *file, int fd, int size)
{
	int	nbr_char;
	int	c;
	int	i;

	nbr_char = 0;
	i = 0;
	while (read(fd, &c, 1))
			nbr_char++;
	close(fd);
	fd = open(file, O_RDWR);
	while (i < nbr_char - size && read(fd, &c, 1))
		i++;
	while (read(fd, &c, 1))
		write(1, &c, 1);
}

void	print_file_name(char *file, int *first)
{
	if (*first)
	{
		ft_putstr("==> ");
		*first = 0;
	}
	else
		ft_putstr("\n==> ");
	ft_putstr(file);
	ft_putstr(" <==\n");
}

void	ft_tail(char **av, int size, int ac)
{
	int	fd;
	int	i;
	int	first;

	i = 0;
	first = 1;
	while (++i < ac)
	{
		if (!ft_strcmp("-c", av[i]))
			i += 2;
		if (i >= ac)
			return ;
		fd = open(av[i], O_RDWR);
		if (fd == -1)
			print_error(av[0], av[i], 0, 0);
		if (fd == -1)
			continue ;
		if (ac != 4)
			print_file_name(av[i], &first);
		write_text(av[i], fd, size);
		close(fd);
	}
}

int	main(int ac, char **av)
{
	int	size;
	int	i;

	i = 0;
	while (++i < ac)
	{
		if (!ft_strcmp("-c", av[i]))
		{
			if (++i < ac)
			{
				size = ft_atoi(av[i]);
				if (print_error(av[0], av[i], 1, size))
					return (0);
				if (write_in_terminal(size, ac, i))
					return (0);
			}
			else
			{
				print_error(av[0], av[i], 2, 0);
				return (0);
			}
		}
	}
	ft_tail(av, size, ac);
}
