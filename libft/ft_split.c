/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ride-sou <ride-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:57:36 by ride-sou          #+#    #+#             */
/*   Updated: 2023/04/26 13:40:30 by ride-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_num_words_count(char const *s, char c)
{
	int	i;
	int	count_words;

	i = 0;
	count_words = 0;
	if (!s || (!*s && c != '\0'))
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			count_words++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (count_words);
}

char	**ft_memory_allocation(char const *s, char c, int count_words)
{
	char	**big_array;

	if (!s || (!*s && c != '\0'))
	{
		big_array = malloc(sizeof(char *) * 1);
		if (big_array == NULL)
			return (NULL);
		big_array[0] = NULL;
	}
	else
	{
		big_array = malloc(sizeof(char *) * (count_words + 1));
		if (big_array == NULL)
			return (NULL);
	}
	return (big_array);
}

char	*ft_inside_the_box(char const *s, int j, int len)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	while (i < len)
	{
		str[i] = s[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**big_array;
	int		count_words;
	int		word_len;
	int		i;
	int		k;

	k = 0;
	i = 0;
	count_words = ft_num_words_count(s, c);
	big_array = ft_memory_allocation(s, c, count_words);
	if (big_array == NULL)
		return (NULL);
	while (k < count_words)
	{
		while (s[i] == c)
			i++;
		word_len = 0;
		while (s[i + word_len] != '\0' && s[i + word_len] != c)
			word_len++;
		big_array[k] = ft_inside_the_box(s, i, word_len);
		i = i + word_len;
		k++;
	}
	big_array[k] = NULL;
	return (big_array);
}
