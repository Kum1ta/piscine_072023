/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbernar <edbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 21:33:50 by edbernar          #+#    #+#             */
/*   Updated: 2023/07/31 20:04:02 by edbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <libgen.h>

void	print_addr(long int addr, int c);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
void	print_error(char *prog_name, char *file);
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(char *str);
void	print_text_no_c(char *str);
void	init(char *str, char *last_str, int i[5], int long *letter);
void	write_text_c(char *str);

void	print_line(char *last_str, char *str, long int *letter, int *j)
{
	*j = 0;
	if (ft_strncmp(last_str, str, 16))
	{
		print_addr(*letter, 0);
		print_text_no_c(str);
		ft_strncpy(last_str, str, 16);
		last_str[16] = 0;
	}
	else if (!ft_strncmp(last_str, str, 15) && last_str[16] != '*')
	{
		last_str[16] = '*';
		write(1, "*\n", 2);
	}
	else
		last_str[16] = '*';
	*letter += 16;
}

int	open_file(char **av, int *i, int *fd, int *new_file)
{
	*fd = open(av[*i], O_RDWR);
	if (*fd == -1)
	{
		print_error(av[0], av[*i]);
		*i = *i + 1;
		return (-1);
	}
	*new_file = 0;
	return (0);
}

void	print_end(long int letter, int j, char *str, char *last_str)
{
	int	i;

	i = j;
	while (j < 16)
		str[j++] = 0;
	if (!ft_strncmp(last_str, str, i))
	{
		letter += ft_strlen(str);
		print_addr(letter, 0);
	}
	else
	{
		print_addr(letter, 0);
		print_text_no_c(str);
		letter += ft_strlen(str);
		print_addr(letter, 0);
	}
	write(1, "\n", 1);
}

void	function_without_c(char **av, int ac)
{
	long int	letter;
	char		str[16];
	char		last_str[17];
	int			i[5];

	init(str, last_str, i, &letter);
	while (i[1] < ac)
	{
		if (i[3] && open_file(av, &i[1], &i[0], &i[3]) == -1)
			continue ;
		while (i[2] < 16 && read(i[0], &i[4], 1))
			str[i[2]++] = i[4];
		if (i[2] == 16)
			print_line(last_str, str, &letter, &i[2]);
		else
		{
			i[3] = 1;
			i[1]++;
		}
	}
	if (letter || i[2] != 0)
		print_end(letter, i[2], str, last_str);
}

void	print_text_c(char *str)
{
	int	i;

	i = -1;
	while (str[++i] && i < 16)
	{
		if (i == 0 || i == 8)
			write(1, " ", 1);
		write(1, " ", 1);
		write(1, &"0123456789abcdef"[str[i] / 16], 1);
		write(1, &"0123456789abcdef"[str[i] % 16], 1);
	}
	while (i < 16)
	{
		if (i == 0 || i == 8)
			write(1, " ", 1);
		write(1, "   ", 3);
		i++;
	}
	write(1, "  |", 3);
	write_text_c(str);
	write(1, "|\n", 2);
}
