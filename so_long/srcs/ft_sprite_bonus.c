/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 09:18:11 by dilopez-          #+#    #+#             */
/*   Updated: 2022/07/05 14:19:02 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"
#include <stdio.h>

void	ft_put_sprites(t_program *program)
{
	int			y;
	int			x;

	ft_create_sprite(program, &program->sprite, "sprites/cube.xpm");
	ft_create_sprite(program, &program->floor, "sprites/floor.xpm");
	ft_create_sprite(program, &program->coin, "sprites/coin1.xpm");
	ft_create_sprite(program, &program->wall, "sprites/wall.xpm");
	ft_create_sprite(program, &program->exit, "sprites/exit.xpm");
	ft_create_sprite(program, &program->thorn, "sprites/thorn.xpm");
	program->coins = 0;
	y = 0;
	while (y < (program->map)->height)
	{
		x = 0;
		while (x < (program->map)->width)
		{
			ft_put_chars_sprites(program, x, y);
			x++;
		}
		y++;
	}
	mlx_string_put(program->mlx, program->window.reference, \
					20, 36, -255, "Movements: 0");
}

void	ft_put_chars_sprites(t_program *program, int x, int y)
{
	mlx_put_image_to_window(program->mlx, program->window.reference,
		program->floor.reference, x * 64, y * 64);
	if ((program->map)->ber[y][x] == '1')
		mlx_put_image_to_window(program->mlx, program->window.reference,
			program->wall.reference, x * 64, y * 64);
	if ((program->map)->ber[y][x] == 'C' && ++(program->coins))
		mlx_put_image_to_window(program->mlx, program->window.reference,
			program->coin.reference, x * 64, y * 64);
	if ((program->map)->ber[y][x] == 'E')
		mlx_put_image_to_window(program->mlx, program->window.reference,
			program->exit.reference, x * 64, y * 64);
	if ((program->map)->ber[y][x] == 'T')
		mlx_put_image_to_window(program->mlx, program->window.reference,
			program->thorn.reference, x * 64, y * 64);
	if ((program->map)->ber[y][x] == 'P'
		&& program->sprite_position.x == 0
		&& program->sprite_position.y == 0)
	{
		program->movements = 0;
		program->sprite_position.x = x * 64;
		program->sprite_position.y = y * 64;
		mlx_put_image_to_window(program->mlx, program->window.reference,
			program->sprite.reference, x * 64, y * 64);
	}
}

void	ft_create_sprite(t_program *program, t_sprite *sprite, char *path)
{
	sprite->reference = mlx_xpm_file_to_image(program->mlx, path,
			&sprite->size.x, &sprite->size.y);
	sprite->pixels = mlx_get_data_addr(sprite->reference, \
		&sprite->bits_per_pixel, &sprite->line_size, &sprite->endian);
}
