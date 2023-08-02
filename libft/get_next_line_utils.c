/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ride-sou <ride-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 08:43:04 by ride-sou          #+#    #+#             */
/*   Updated: 2023/06/27 17:57:40 by ride-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen_gnl(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr_gnl(char *temp, char line_break)
{
	int	i;

	i = 0;
	if (!temp)
		return (0);
	while (temp[i] != '\0')
	{
		if (temp[i] == line_break)
			return (&temp[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin_gnl(char *temp, char *buffer)
{
	int		i;
	int		j;
	int		strlen_temp_buffer;
	char	*strjoin;

	i = -1;
	j = 0;
	if (!temp)
	{
		temp = malloc(sizeof(char) * 1);
		temp[0] = '\0';
	}
	if (!temp || !buffer)
		return (NULL);
	strlen_temp_buffer = ft_strlen_gnl(temp) + ft_strlen_gnl(buffer);
	strjoin = malloc(sizeof(char) *(strlen_temp_buffer + 1));
	if (!strjoin)
		return (NULL);
	while (temp[++i] != '\0')
		strjoin[i] = temp[i];
	while (buffer[j] != '\0')
		strjoin[i++] = buffer[j++];
	strjoin[i] = '\0';
	free(temp);
	return (strjoin);
}

char	*ft_new_temp(char *temp)
{
	int		i;
	int		j;
	char	*new_temp;

	i = 0;
	j = 0;
	while (temp[i] != '\n' && temp[i] != '\0')
		i++;
	if (temp[i] == 0)
	{
		free(temp);
		return (NULL);
	}
	new_temp = malloc(sizeof(char) * (ft_strlen_gnl(temp) - i + 1));
	if (!new_temp)
		return (NULL);
	i = i + 1;
	while (temp[i] != '\0')
		new_temp[j++] = temp[i++];
	new_temp[j] = '\0';
	free(temp);
	new_temp = ft_new_temp_aux(new_temp);
	return (new_temp);
}

char	*ft_new_temp_aux(char *new_temp)
{
	if (new_temp[0] == '\0')
	{
		free (new_temp);
		new_temp = 0;
	}
	return (new_temp);
}
