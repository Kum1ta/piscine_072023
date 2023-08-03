/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbernar <edbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 13:27:42 by edbernar          #+#    #+#             */
/*   Updated: 2023/07/18 12:01:19 by edbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	put_x(char (*tab)[10][10], int pos_x, int pos_y)
{
	int	x;
	int	y;

	x = -1;
	while (++x < 10)
		(*tab)[pos_y][x] = 'x';
	y = -1;
	while (++y < 10)
		(*tab)[y][pos_x] = 'x';
	x = pos_x + 1;
	y = pos_y;
	while (--x > 0 && y > 0)
		y--;
	while ((y > -1 && y < 10) && (x > -1 && x++ < 10))
		(*tab)[y++][x - 1] = 'x';
	x = pos_x - 1;
	y = pos_y;
	while (++x < 9 && y > 0)
		y--;
	while ((y > -1 && y < 10) && (x > -1 && x-- < 10))
		(*tab)[y++][x + 1] = 'x';
	(*tab)[pos_y][pos_x] = 'O';
}

void	print_queen(char tab[10][10])
{
	int	x;
	int	y;

	x = 0;
	while (x < 10)
	{
		y = 0;
		while (y < 10)
		{
			if (tab[y][x] == 'O')
				write(1, &(char){y + 48}, 1);
			y++;
		}
		x++;
	}
	write(1, "\n", 1);
}

void	copy_tab(char tab[10][10], char (*new_tab)[10][10])
{
	int	x;
	int	y;

	y = 0;
	while (y < 10)
	{
		x = 0;
		while (x < 10)
		{
			(*new_tab)[y][x] = tab[y][x];
			x++;
		}
		y++;
	}
}

char	(*ft_ten_queens_puzzle_rec(char tab[10][10], int col, int *nbr))[10]
{
	char	new_tab[10][10];
	int		i;

	if (col > 9)
	{
		*nbr = *nbr + 1;
		print_queen(tab);
		return (tab);
	}
	i = -1;
	while (++i < 10)
	{
		if (tab[i][col] == '.')
		{
			copy_tab(tab, &new_tab);
			put_x(&new_tab, col, i);
			ft_ten_queens_puzzle_rec(new_tab, col + 1, nbr);
		}
	}
	return (0);
}

int	ft_ten_queens_puzzle(void)
{
	char	tab[10][10];
	int		nbr;
	int		x;
	int		y;

	x = 0;
	nbr = 0;
	while (x < 10)
	{
		y = 0;
		while (y < 10)
		{
			tab[x][y] = '.';
			y++;
		}
		x++;
	}
	ft_ten_queens_puzzle_rec(tab, 0, &nbr);
	return (nbr);
}
