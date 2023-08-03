/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbernar <edbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 19:04:23 by edbernar          #+#    #+#             */
/*   Updated: 2023/07/27 15:35:31 by edbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
}

int	ft_atoi(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (-1);
		result = (result * 10) + (str[i] - 48);
		i++;
	}
	return (result);
}

void	ft_memmove(char *str, char c, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		str[i] = str[i + 1];
		i++;
	}
	str[i] = c;
	str[i + 1] = 0;
}

int	write_in_terminal(int size, int ac, int j)
{
	char	*str;
	char	c;
	int		i;

	if (size == 0)
		return (1);
	if (j + 1 != ac && ac != 3)
		return (0);
	str = malloc((size + 1) * sizeof(char));
	if (str == NULL)
		return (1);
	i = -1;
	while (++i < size)
		str[i] = 0;
	i = 0;
	while (read(0, &c, 1))
	{
		if (i < size)
			str[i] = c;
		else
			ft_memmove(str, c, size);
		i++;
	}
	ft_putstr(str);
	return (1);
}
