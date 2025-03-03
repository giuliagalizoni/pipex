/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalizon <ggalizon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:06:28 by ggalizon          #+#    #+#             */
/*   Updated: 2024/11/26 10:51:58 by ggalizon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	const char	*keep;
	const char	*last;

	keep = str;
	last = ((void *)0);
	while (*str)
		str++;
	while (str >= keep)
	{
		if (*str == (char)c)
		{
			last = str;
			break ;
		}
		str--;
	}
	return ((char *)last);
}
