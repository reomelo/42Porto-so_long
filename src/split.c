/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:52:13 by riolivei          #+#    #+#             */
/*   Updated: 2022/12/07 18:56:51 by riolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_words(char *s, char c)
{
	int	words;
	int	flag;

	words = 0;
	flag = 0;
	while (*s)
	{
		if (*s != c && flag == 0)
		{
			flag = 1;
			words++;
		}
		else if (*s == c)
			flag = 0;
		s++;
	}
	return (words);
}

int	count_letters(char *s, char c, int i)
{
	int	size;

	size = 0;
	while (s[i] != c && s[i])
	{
		size++;
		i++;
	}
	return (size);
}

char	**ft_split(t_props *props, char c)
{
	int		i;
	int		j;
	char	**str;

	if (!props->map.buff)
		return (NULL);
	i = 0;
	j = -1;
	props->map.lines = count_words(props->map.buff, c);
	str = (char **)malloc((props->map.lines + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	while (++j < props->map.lines)
	{
		while (props->map.buff[i] == c)
			i++;
		str[j] = ft_substr(props->map.buff, i,
				count_letters(props->map.buff, c, i));
		if (!str)
			return (NULL);
		i += count_letters(props->map.buff, c, i);
	}
	str[j] = 0;
	props->map.cols = ft_strlen(str[0]);
	return (str);
}
