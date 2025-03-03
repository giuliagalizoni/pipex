/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalizon <ggalizon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:37:13 by ggalizon          #+#    #+#             */
/*   Updated: 2024/12/09 10:39:58 by ggalizon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_neg(long *nb, int *len)
{
	int	re;

	re = write(1, "-", 1);
	*len += re;
	*nb = -(*nb);
	return (re);
}

int	ft_putnbr(int n)
{
	long	nb;
	char	d;
	int		len;
	int		re;

	nb = n;
	len = 0;
	re = 0;
	if (nb < 0)
	{
		if (handle_neg(&nb, &len) == -1)
			return (-1);
	}
	if (nb >= 10)
	{
		re = ft_putnbr(nb / 10);
		if (re == -1)
			return (re);
		len += re;
	}
	d = (nb % 10) + '0';
	re = write(1, &d, 1);
	if (re == -1)
		return (re);
	return (len + 1);
}
