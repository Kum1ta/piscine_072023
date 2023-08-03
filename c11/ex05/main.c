/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbernar <edbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:37:29 by edbernar          #+#    #+#             */
/*   Updated: 2023/07/29 20:37:14 by edbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	addition(int a, int b);
void	soustract(int a, int b);
void	multiplication(int a, int b);
void	division(int a, int b);
void	modulo(int a, int b);

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	write(1, &(char){nb % 10 + 48}, 1);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	while ((str[i] >= 7 && str[i] <= 13) || str[i] == ' ')
		i++;
	sign = 1;
	while (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	result = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - 48);
		i++;
	}
	return (result * sign);
}

void	ft_calcul(char **av, void (**f)(int, int))
{
	if (!ft_strcmp(av[2], "+"))
		f[0](ft_atoi(av[1]), ft_atoi(av[3]));
	else if (!ft_strcmp(av[2], "-"))
		f[1](ft_atoi(av[1]), ft_atoi(av[3]));
	else if (!ft_strcmp(av[2], "*"))
		f[2](ft_atoi(av[1]), ft_atoi(av[3]));
	else if (!ft_strcmp(av[2], "/"))
	{
		if (!ft_atoi(av[3]))
			write(1, "Stop : division by zero", 23);
		else
			f[3](ft_atoi(av[1]), ft_atoi(av[3]));
	}
	else if (!ft_strcmp(av[2], "%"))
	{
		if (!ft_atoi(av[3]))
			write(1, "Stop : modulo by zero", 21);
		else
			f[4](ft_atoi(av[1]), ft_atoi(av[3]));
	}
	else
		write(1, "0", 1);
	write(1, "\n", 1);
}

int	main(int ac, char **av)
{
	void	(*f[5])(int, int);

	f[0] = &addition;
	f[1] = &soustract;
	f[2] = &multiplication;
	f[3] = &division;
	f[4] = &modulo;
	if (ac != 4)
		return (0);
	ft_calcul(av, f);
}
