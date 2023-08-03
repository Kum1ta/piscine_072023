/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbernar <edbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:37:24 by edbernar          #+#    #+#             */
/*   Updated: 2023/07/14 22:13:28 by edbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_hexa(long int nb)
{
	if (nb > 16)
		ft_putnbr_hexa(nb / 16);
	write(1, &"0123456789abcdef"[nb % 16], 1);
}

void	print_adresse(void *addr)
{
	long int	cpy_addr;
	int			adress_size;
	int			i;

	adress_size = 0;
	cpy_addr = (long int)addr;
	while (cpy_addr)
	{
		cpy_addr /= 16;
		adress_size++;
	}
	i = -1;
	while (++i < 15 - adress_size)
		write(1, "0", 1);
	ft_putnbr_hexa((long)addr);
	write(1, ":", 1);
}

void	print_hexa_text(unsigned char *str, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (str[i] && i < 16 && i < size)
	{
		if (i % 2 == 0)
			write(1, " ", 1);
		write(1, &"0123456789abcdef"[str[i] / 16], 1);
		write(1, &"0123456789abcdef"[str[i] % 16], 1);
		i++;
	}
	while (i < 16)
	{
		if (i % 2 == 0)
			write(1, " ", 1);
		write(1, "  ", 2);
		i++;
	}
	write(1, " ", 1);
}

void	print_text(unsigned char *str, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (str[i] && i < 16 && i < size)
	{
		if (!(str[i] >= 32 && str[i] <= 126))
			write(1, ".", 1);
		else
			write(1, &str[i], 1);
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	start;

	start = 0;
	while (start < size)
	{
		print_adresse(addr + start);
		print_hexa_text((unsigned char *)(addr + start), size);
		print_text((unsigned char *)(addr + start), size);
		write(1, "\n", 1);
		start += 16;
	}
	return (addr);
}
