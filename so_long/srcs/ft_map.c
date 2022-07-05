/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 18:01:28 by dilopez-          #+#    #+#             */
/*   Updated: 2022/07/05 14:15:25 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_get_map(t_program *program, char *ber)
{
	char	*str_map;
	char	*line;
	int		fd;

	program->map = ft_calloc(1, sizeof(t_map));
	fd = open(ber, O_RDONLY);
	line = get_next_line(fd);
	str_map = 0;
	str_map = ft_strjoin(line, "");
	line = get_next_line(fd);
	while (line)
	{
		str_map = ft_strjoin(str_map, line);
		free(line);
		line = get_next_line(fd);
	}
	(program->map)->ber = ft_split(str_map, '\n');
	if (!str_map || ft_check_map(program))
	{
		if (str_map)
			ft_free_map(&program->map);
		free(str_map);
		ft_exit_program_error("Error: Wrong map");
	}
	free(str_map);
}

int	ft_check_map(t_program *program)
{
	int		height;
	int		pos_row;
	char	**str_map;

	(program->map)->width = ft_strlen(((program->map)->ber)[0]);
	str_map = (program->map)->ber;
	height = -1;
	while (str_map[++height])
	{
		if (height == 0)
			pos_row = 0;
		else if (str_map[height + 1])
			pos_row = 1;
		else
			pos_row = 2;
		if (ft_check_chars_map(str_map[height], (program->map)->width, pos_row))
			return (1);
	}
	if (height < 3)
		return (1);
	(program->map)->height = height;
	return (0);
}

int	ft_check_chars_map(char *row, int width, int pos_row)
{
	char	c;
	int		width_loop;
	int		double_char;

	double_char = -1;
	width_loop = 0;
	while (row[width_loop])
	{
		c = row[width_loop];
		if ((pos_row == 0 || pos_row == 2) && c != '1')
			return (1);
		else if ((width_loop == 0 || width_loop == width - 1) && c != '1')
			return (1);
		if (c != '1' && c != '0' && c != 'P' && c != 'C' && c != 'E'
			&& c != 'T')
			return (1);
		if (c == 'P')
			double_char++;
		if (double_char == 1)
			return (1);
		width_loop++;
	}
	if (width_loop != width)
		return (1);
	return (0);
}

void	ft_free_map(t_map **map)
{
	int	i;

	i = 0;
	while (((*map)->ber)[i])
	{
		free(((*map)->ber)[i]);
		i++;
	}
	free((*map)->ber);
	free(*map);
}
