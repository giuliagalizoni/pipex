/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalizon <ggalizon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:11:01 by ggalizon          #+#    #+#             */
/*   Updated: 2024/11/26 10:50:11 by ggalizon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(long nb)
{
	int	count;

	count = 0;
	if (nb == 0)
		count = 1;
	while (nb > 0)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

static int	is_negative(long *nb)
{
	if (*nb < 0)
	{
		*nb = -(*nb);
		return (1);
	}
	return (0);
}

char	*ft_itoa(int n)
{
	long	nb;
	char	*str;
	int		flag;
	int		i;

	nb = n;
	flag = is_negative(&nb);
	str = malloc(count(nb) + flag + 1);
	if (str == NULL)
		return (NULL);
	str[count(nb) + flag] = '\0';
	i = count(nb) + flag - 1;
	if (nb == 0)
		str[i] = '0';
	while (nb > 0)
	{
		str[i] = (nb % 10) + '0';
		nb /= 10;
		i--;
	}
	if (flag)
		str[0] = '-';
	return (str);
}
