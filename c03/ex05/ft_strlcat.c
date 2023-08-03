/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbernar <edbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 00:04:29 by edbernar          #+#    #+#             */
/*   Updated: 2023/07/16 10:40:41 by edbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
			i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	j = 0;
	i = 0;
	while (dest[i] && i < size)
			i++;
	while (src[j] && size != 0 && i + j < size - 1)
	{
			dest[i + j] = src[j];
			j++;
	}
	if (i < size)
			dest[i + j] = 0;
	j = ft_strlen(src);
	return (i + j);
}
