/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ride-sou <ride-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:24:38 by ride-sou          #+#    #+#             */
/*   Updated: 2023/04/18 17:17:20 by ride-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi_aux(const char *str, int i)
{
	int	number;

	number = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		number = number * 10;
		number = number + str[i] - 48;
		i++;
	}
	return (number);
}

int	ft_atoi(const char *str)
{
	int	minus_sign;
	int	number;
	int	plus_sign;
	int	i;

	minus_sign = 0;
	plus_sign = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus_sign++;
		if (str[i] == '+')
			plus_sign++;
		i++;
	}
	number = ft_atoi_aux(str, i);
	if (minus_sign + plus_sign > 1)
		return (0);
	if ((minus_sign % 2 == 0))
		return (number);
	return (-number);
}
