/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_ptr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ride-sou <ride-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 10:44:33 by ride-sou          #+#    #+#             */
/*   Updated: 2023/05/30 12:02:11 by ride-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hex_ptr_len(unsigned long num)
{
	int	len;

	len = 0;
	while (num > 0)
	{
		num = num / 16;
		len++;
	}
	return (len);
}

void	ft_put_hex_ptr(unsigned long num, const char format)
{
	if (num >= 16)
	{
		ft_put_hex_ptr(num / 16, format);
		ft_put_hex_ptr(num % 16, format);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
		{
			if (format == 'x' || format == 'p')
				ft_putchar_fd((num - 10 + 'a'), 1);
			if (format == 'X')
				ft_putchar_fd((num - 10 + 'A'), 1);
		}
	}
}

int	ft_print_hex(unsigned int num, const char format)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_put_hex_ptr(num, format);
	return (ft_hex_ptr_len(num));
}

int	ft_print_ptr(unsigned long ptr, const char format)
{
	int	ptr_len;

	ptr_len = 0;
	if (ptr == 0)
		return (write(1, "(nil)", 5));
	ptr_len = write(1, "0x", 2);
	ft_put_hex_ptr(ptr, format);
	ptr_len += ft_hex_ptr_len(ptr);
	return (ptr_len);
}
