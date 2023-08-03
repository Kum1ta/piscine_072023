/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbernar <edbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:48:42 by edbernar          #+#    #+#             */
/*   Updated: 2023/07/26 11:32:35 by edbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putnbr(int nb);

void	addition(int a, int b)
{
	ft_putnbr(a + b);
}

void	soustract(int a, int b)
{
	ft_putnbr(a - b);
}

void	multiplication(int a, int b)
{
	ft_putnbr(a * b);
}

void	division(int a, int b)
{
	ft_putnbr(a / b);
}

void	modulo(int a, int b)
{
	ft_putnbr(a % b);
}
