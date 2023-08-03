/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycontre <ycontre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 10:23:37 by ycontre           #+#    #+#             */
/*   Updated: 2023/07/15 10:59:20 by ycontre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_line(int x, char start_char, char end_char, char c)
{
	int	i;

	ft_putchar(start_char);
	i = 0;
	while (i < x)
	{
		ft_putchar(c);
		i++;
	}
	if (x >= 0)
		ft_putchar(end_char);
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	i;

	i = 0;
	while (i < y)
	{
		if (i == 0)
			ft_line(x - 2, 'A', 'C', 'B');
		else if (i == y - 1)
			ft_line(x - 2, 'A', 'C', 'B');
		else
			ft_line(x - 2, 'B', 'B', ' ');
		i++;
	}
}
