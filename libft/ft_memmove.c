/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalizon <ggalizon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:45:00 by ggalizon          #+#    #+#             */
/*   Updated: 2024/11/26 10:51:00 by ggalizon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n);

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char				*dst;
	const char			*source;

	if (!dest && !src)
		return (NULL);
	if (dest == src || n == 0)
		return (dest);
	dst = (char *)dest;
	source = (const char *)src;
	if (dst > source && dst < source + n)
	{
		while (n > 0)
		{
			n--;
			dst[n] = source[n];
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
