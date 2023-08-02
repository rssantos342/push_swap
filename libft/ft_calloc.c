/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ride-sou <ride-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:39:42 by ride-sou          #+#    #+#             */
/*   Updated: 2023/04/24 20:02:54 by ride-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*mem;
	size_t	totalsize;
	size_t	i;

	i = 0;
	totalsize = nmemb * size;
	mem = malloc(totalsize);
	if (mem == NULL)
		return (0);
	while (i < totalsize)
	{
		mem[i] = 0;
		i++;
	}
	return (mem);
}
