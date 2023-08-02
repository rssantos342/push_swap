/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ride-sou <ride-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:55:09 by ride-sou          #+#    #+#             */
/*   Updated: 2023/05/30 12:02:12 by ride-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_num_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num > 0)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char	*str;
	int		len;

	len = ft_num_len(n);
	str = (char *)malloc(sizeof(char *) * (len + 1));
	if (str == 0)
		return (NULL);
	str[len] = '\0';
	while (n > 0)
	{
		str[len - 1] = 48 + (n % 10);
		n = n / 10;
		len--;
	}
	return (str);
}

int	ft_print_unsigned(unsigned int n)
{
	int		len_unsg;
	char	*num;

	len_unsg = 0;
	if (n == 0)
		len_unsg = write(1, "0", 1);
	else
	{
		num = ft_uitoa(n);
		len_unsg = ft_printstr(num);
		free(num);
	}
	return (len_unsg);
}
