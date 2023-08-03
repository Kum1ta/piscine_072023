/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbernar <edbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 21:35:18 by edbernar          #+#    #+#             */
/*   Updated: 2023/07/27 17:33:08 by edbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <libgen.h>

void	print_line(char *last_str, char *str, long int *letter, int *j);
void	print_end(long int letter, int j, char *str, char *last_str);
void	init(char *str, char *last_str, int i[5], int long *letter);
int		open_file(char **av, int *i, int *fd, int *new_file);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
void	init_str(char *str, char *last_str);
void	print_addr(long int addr, int c);
int		ft_strcmp(char *s1, char *s2);
void	write_text_c(char *str);
void	print_text_c(char *str);
int		ft_strlen(char *str);

void	print_end_c(long int letter, int j, char *str, char *last_str)
{
	int	i;

	i = j;
	if (letter == 0 && j != 0)
		return ;
	while (j < 16)
		str[j++] = 0;
	if (!ft_strncmp(last_str, str, i))
	{
		letter += ft_strlen(str);
		print_addr(letter, 1);
	}
	else
	{
		print_addr(letter, 1);
		print_text_c(str);
		letter += ft_strlen(str);
		print_addr(letter, 1);
	}
	write(1, "\n", 1);
}

void	print_line_c(char *last_str, char *str, long int *letter, int *j)
{
	*j = 0;
	if (ft_strncmp(last_str, str, 16))
	{
		print_addr(*letter, 1);
		print_text_c(str);
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

void	function_with_c(char **av, int ac)
{
	char		last_str[17];
	long int	letter;
	char		str[16];
	int			i[5];

	init(str, last_str, i, &letter);
	while (i[1] < ac)
	{
		if (!ft_strcmp("-C", av[i[1]]))
			i[1]++;
		if (i[1] >= ac)
			break ;
		if (i[3] && open_file(av, &i[1], &i[0], &i[3]) == -1)
			continue ;
		while (i[2] < 16 && read(i[0], &i[4], 1))
			str[i[2]++] = i[4];
		if (i[2] == 16)
			print_line_c(last_str, str, &letter, &i[2]);
		else
		{
			i[3] = 1;
			i[1]++;
		}
	}
	print_end_c(letter, i[2], str, last_str);
}

void	write_in_terminal_c(void)
{
	long int	letter;
	char		last_str[17];
	char		str[16];
	char		c;
	int			i;

	i = 0;
	letter = 0;
	while (read(0, &c, 1))
	{
		str[i] = c;
		i++;
		if (i == 16)
			print_line_c(last_str, str, &letter, &i);
	}
	print_end_c(letter, i, str, last_str);
}

void	write_in_terminal(void)
{
	long int	letter;
	char		last_str[17];
	char		str[16];
	char		c;
	int			i;

	i = 0;
	letter = 0;
	while (read(0, &c, 1))
	{
		str[i] = c;
		i++;
		if (i == 16)
			print_line(last_str, str, &letter, &i);
	}
	print_end(letter, i, str, last_str);
}
