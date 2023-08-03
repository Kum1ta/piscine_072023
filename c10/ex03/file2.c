/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbernar <edbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 21:32:59 by edbernar          #+#    #+#             */
/*   Updated: 2023/07/31 17:57:40 by edbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <libgen.h>

void	ft_putnbr_hexa(long int nb);

void	print_addr(long int addr, int c)
{
	long int	cpy_addr;
	int			adress_size;
	int			i;

	adress_size = 0;
	cpy_addr = addr;
	if (addr == 0 && c == 0)
	{
		write(1, "0000000", 7);
		return ;
	}
	else if (addr == 0 && c == 1)
	{
		write(1, "00000000", 8);
		return ;
	}
	while (cpy_addr)
	{
		cpy_addr /= 16;
		adress_size++;
	}
	i = -1;
	while (++i < 7 - adress_size + c)
		write(1, "0", 1);
	ft_putnbr_hexa(addr);
}

void	print_text_no_c(char *str)
{
	int	i;

	i = 0;
	while (str[i] && i < 16)
	{
		if (i % 2 == 0)
			write(1, " ", 1);
		write(1, &"0123456789abcdef"[str[i + 1] / 16], 1);
		write(1, &"0123456789abcdef"[str[i + 1] % 16], 1);
		write(1, &"0123456789abcdef"[str[i] / 16], 1);
		write(1, &"0123456789abcdef"[str[i] % 16], 1);
		i += 2;
	}
	while (i < 16)
	{
		if (i % 2 == 0)
			write(1, " ", 1);
		write(1, "    ", 4);
		i += 2;
	}
	write(1, "\n", 1);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = -1;
	while (src[++i] && i < n)
		dest[i] = src[i];
	while (i < n)
	{
		dest[i] = 0;
		i++;
	}
	return (dest);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	init(char *str, char *last_str, int i[5], int long *letter)
{
	int	j;

	j = 0;
	*letter = 0;
	i[2] = 0;
	i[3] = 1;
	i[1] = 1;
	while (++j < 16)
	{
		str[j] = 0;
		last_str[j] = 0;
	}
}
