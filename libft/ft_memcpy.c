/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalizon <ggalizon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:05:49 by ggalizon          #+#    #+#             */
/*   Updated: 2024/11/26 10:50:57 by ggalizon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char			*dst;
	const char		*source;
	size_t			i;

	if (!dest && !src)
		return (NULL);
	dst = dest;
	source = src;
	i = 0;
	while (i < n)
	{
		dst[i] = source[i];
		i++;
	}
	return (dst);
}
