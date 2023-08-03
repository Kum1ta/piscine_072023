/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbernar <edbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 23:28:39 by edbernar          #+#    #+#             */
/*   Updated: 2023/07/27 13:14:44 by edbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <libgen.h>

void	function_without_c(char **av, int ac);
void	function_with_c(char **av, int ac);
int		ft_strcmp(char *s1, char *s2);
void	write_in_terminal_c(void);
void	write_in_terminal(void);

void	init_str(char *str, char *last_str)
{
	int	i;

	i = 0;
	while (++i < 16)
	{
		str[i] = 0;
		last_str[i] = 0;
	}
}

void	write_text_c(char *str)
{
	int	i;

	i = -1;
	while (str[++i] && i < 16)
	{
		if (!(str[i] >= 32 && str[i] <= 126))
			write(1, ".", 1);
		else
			write(1, &str[i], 1);
	}
}

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 2 && !ft_strcmp("-C", av[1]))
	{
		write_in_terminal_c();
		return (0);
	}
	if (ac == 1)
	{
		write_in_terminal();
		return (0);
	}
	while (++i < ac)
	{
		if (ft_strcmp(av[i], "-C") == 0)
		{
			function_with_c(av, ac);
			return (0);
		}
	}
	function_without_c(av, ac);
}
