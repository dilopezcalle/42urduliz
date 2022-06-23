/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:49:54 by dilopez-          #+#    #+#             */
/*   Updated: 2022/06/18 15:13:26 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

char	**ft_split(char const *s, char c)
{
	char	**bi_str;
	int		rows;
	int		i;

	if (!s)
		return (NULL);
	rows = ft_split_check_rows(s, c);
	if (c == '\0' && ft_strlen(s) > 0)
		rows = 1;
	bi_str = (char **)ft_calloc(rows + 1, sizeof(char *));
	if (bi_str == NULL)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		bi_str[i] = ft_split_check_chars(s, c, i);
		if (bi_str[i] == NULL)
			return (NULL);
		i++;
	}
	bi_str[i] = NULL;
	return (bi_str);
}

int	ft_split_check_rows(char const *s, char c)
{
	int	rows;
	int	i;

	i = 0;
	rows = 0;
	while (s[i])
	{
		if (s[i] != c && s[i] != 39)
			rows++;
		while (s[i] && (s[i] != c || s[i] == 39))
		{
			if (s[i] == 39)
			{
				rows++;
				i++;
				while (s[i] && s[i] != 39)
					i++;
			}
			i++;
		}
		if (s[i])
			i++;
	}
	return (rows);
}

char	*ft_split_check_chars(char const *s, char c, int row)
{
	int		i;
	int		counter;
	char	*str_row;

	str_row = NULL;
	i = -1;
	counter = -1;
	while (++i < (int)ft_strlen(s) && s[i])
	{
		if (s[i] != c)
			counter++;
		if (counter == row && s[i] != c)
		{
			str_row = ft_split_generate_str(s, c, i);
			if (!str_row)
				return (NULL);
		}
		while (s[i] && s[i] != c)
			if (s[i++] == 39)
				while (s[i] && s[i] != 39)
					i++;
	}
	return (str_row);
}

char	*ft_split_generate_str(char const *s, char c, int i)
{
	char	*str_row;
	int		counter;

	counter = i;
	if (s[counter++] == 39)
	{
		while (s[counter] && s[counter] != 39)
			counter++;
		str_row = ft_substr(s, i + 1, counter - i - 1);
	}
	else
	{
		while (s[counter] && s[counter] != c)
			counter++;
		str_row = ft_substr(s, i, counter - i);
	}
	return (str_row);
}
