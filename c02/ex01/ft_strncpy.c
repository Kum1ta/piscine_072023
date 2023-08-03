/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbernar <edbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 22:11:52 by edbernar          #+#    #+#             */
/*   Updated: 2023/07/11 22:14:20 by edbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
