/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalizon <ggalizon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:02:16 by ggalizon          #+#    #+#             */
/*   Updated: 2024/12/05 13:36:27 by ggalizon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;
	int	re;

	if (!s)
		return (write(1, "(null)", 6));
	i = 0;
	while (s[i])
	{
		re = write(1, &s[i], 1);
		if (re == -1)
			return (re);
		i++;
	}
	return (i);
}
