/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalizon <ggalizon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:34:21 by ggalizon          #+#    #+#             */
/*   Updated: 2024/11/26 10:49:43 by ggalizon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	i;
	int	number;
	int	flag;

	i = 0;
	number = 0;
	flag = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		(i)++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			flag = (flag) * -1;
		i++;
	}
	if (str[i] < '0' || str[i] > '9')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + (str[i] - '0');
		i++;
	}
	return (number * flag);
}
