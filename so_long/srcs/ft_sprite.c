/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 09:18:11 by dilopez-          #+#    #+#             */
/*   Updated: 2022/07/01 19:06:01 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_create_sprite(t_program *program, t_image *sprite, char *path)
{
	sprite->reference = mlx_xpm_file_to_image(program->mlx, path,
			&sprite->size.x, &sprite->size.y);
	sprite->pixels = mlx_get_data_addr(sprite->reference, \
		&sprite->bits_per_pixel, &sprite->line_size, &sprite->endian);
}

void	ft_put_sprites(t_program *program)
{
	int		y;
	int		x;
	t_image	wall;
	t_image	coin;
	t_image	exit;
	t_image	floor;

	ft_create_sprite(program, &program->sprite, "sprites/cube.xpm");
	ft_create_sprite(program, &floor, "sprites/floor.xpm");
	ft_create_sprite(program, &wall, "sprites/wall.xpm");
	ft_create_sprite(program, &coin, "sprites/coin.xpm");
	ft_create_sprite(program, &exit, "sprites/exit.xpm");
	program->coins = 0;
	y = 0;
	while (y < (program->map)->height)
	{
		x = 0;
		while (x < (program->map)->width)
		{
			mlx_put_image_to_window(program->mlx, program->window.reference,
				floor.reference, x * 64, y * 64);
			if ((program->map)->ber[y][x] == '1')
				mlx_put_image_to_window(program->mlx, program->window.reference,
					wall.reference, x * 64, y * 64);
			if ((program->map)->ber[y][x] == 'C' && ++(program->coins))
				mlx_put_image_to_window(program->mlx, program->window.reference,
					coin.reference, x * 64, y * 64);
			if ((program->map)->ber[y][x] == 'E')
				mlx_put_image_to_window(program->mlx, program->window.reference,
					exit.reference, x * 64, y * 64);
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
			x++;
		}
		y++;
	}
}
