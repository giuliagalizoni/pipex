/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalizon <ggalizon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:23:31 by ggalizon          #+#    #+#             */
/*   Updated: 2024/12/05 13:33:56 by ggalizon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, char c)
{
	char	d;
	int		len;
	int		re;

	len = 0;
	if (n > 15)
	{
		re = ft_puthex(n / 16, c);
		if (re == -1)
			return (re);
		len += re;
	}
	n = n % 16;
	if (n < 10)
		d = n + '0';
	else
	{
		d = n + 87;
		if (c == 'X')
			d -= 32;
	}
	re = write(1, &d, 1);
	if (re == -1)
		return (re);
	return (len + 1);
}
