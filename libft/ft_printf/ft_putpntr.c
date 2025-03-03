/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpntr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalizon <ggalizon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:06:53 by ggalizon          #+#    #+#             */
/*   Updated: 2024/12/09 10:40:11 by ggalizon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthexp(unsigned long n)
{
	char	d;
	int		len;
	int		re;

	len = 0;
	re = 0;
	if (n > 15)
	{
		re = ft_puthexp(n / 16);
		if (re == -1)
			return (re);
		len += re;
	}
	n = n % 16;
	if (n < 10)
		d = n + '0';
	else
		d = n + 87;
	len++;
	re = write(1, &d, 1);
	if (re == -1)
		return (re);
	return (len);
}

int	ft_putpntr(void *p)
{
	unsigned long	n;
	int				len;

	if (p == NULL)
		return (write(1, "(nil)", 5));
	n = (unsigned long)p;
	len = 2;
	if (write(1, "0x", 2) == -1)
		return (-1);
	len += ft_puthexp(n);
	return (len);
}
