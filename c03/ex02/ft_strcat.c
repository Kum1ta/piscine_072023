/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbernar <edbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 23:27:11 by edbernar          #+#    #+#             */
/*   Updated: 2023/07/12 23:40:24 by edbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = -1;
	while (dest[i])
		i++;
	while (src[++j])
		dest[i + j] = src[j];
	dest[i + j] = 0;
	return (dest);
}
