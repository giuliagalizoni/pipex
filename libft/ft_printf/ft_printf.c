/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalizon <ggalizon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:50:33 by ggalizon          #+#    #+#             */
/*   Updated: 2024/12/16 14:14:56 by ggalizon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_type(va_list *ap, const char spec)
{
	int	re;

	re = 0;
	if (spec == 'c')
		re = ft_putchar(va_arg(*ap, int));
	else if (spec == 's')
		re = ft_putstr(va_arg(*ap, char *));
	else if (spec == 'd' || spec == 'i')
		re = ft_putnbr(va_arg(*ap, int));
	else if (spec == 'u')
		re = ft_putuint(va_arg(*ap, unsigned int));
	else if (spec == 'x' || spec == 'X')
		re = ft_puthex(va_arg(*ap, int), spec);
	else if (spec == 'p')
		re = ft_putpntr(va_arg(*ap, void *));
	else if (spec == '%')
		re = ft_putchar('%');
	return (re);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		len;
	int		re;

	va_start(ap, str);
	len = 0;
	while (*str)
	{
		if (*str != '%')
		{
			re = ft_putchar(*str);
			len += re;
		}
		else
		{
			str++;
			re = check_type(&ap, *str);
			len += re;
		}
		if (re == -1)
			return (re);
		str++;
	}
	va_end(ap);
	return (len);
}
