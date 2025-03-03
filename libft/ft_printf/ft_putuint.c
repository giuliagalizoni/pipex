/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalizon <ggalizon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:37:13 by ggalizon          #+#    #+#             */
/*   Updated: 2024/12/05 13:36:50 by ggalizon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putuint(unsigned int n)
{
	char	d;
	int		len;
	int		re;

	len = 0;
	if (n >= 10)
	{
		re = ft_putnbr(n / 10);
		if (re == -1)
			return (re);
		len += re;
	}
	d = (n % 10) + '0';
	re = write(1, &d, 1);
	if (re == -1)
		return (re);
	len += re;
	return (len);
}
