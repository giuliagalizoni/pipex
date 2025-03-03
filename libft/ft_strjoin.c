/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalizon <ggalizon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:04:48 by ggalizon          #+#    #+#             */
/*   Updated: 2024/11/26 10:51:35 by ggalizon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str);

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	joined = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (joined == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < (ft_strlen(s1) + ft_strlen(s2) + 1))
	{
		if (i < ft_strlen(s1))
			joined[i] = s1[i];
		else if (j < ft_strlen(s2))
		{
			joined[i] = s2[j];
			j++;
		}
		i++;
	}
	joined[i - 1] = '\0';
	return (joined);
}
