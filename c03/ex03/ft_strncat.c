/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbernar <edbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 23:38:55 by edbernar          #+#    #+#             */
/*   Updated: 2023/07/15 21:01:58 by edbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = -1;
	while (dest[i])
		i++;
	while (src[++j] && j < nb)
		dest[i + j] = src[j];
	dest[i + j] = 0;
	return (dest);
}
