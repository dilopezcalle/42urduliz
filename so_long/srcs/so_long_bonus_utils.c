/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 11:41:04 by dilopez-          #+#    #+#             */
/*   Updated: 2022/07/05 10:19:44 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	ft_update_sprites(void *param)
{
	t_program	*program;
	static int	frame;

	program = (t_program *)param;
	ft_update_coins(program);
	frame++;
	if (frame == 10)
		program->sprite_position.y += 1;
	else if (frame >= 10 * 2)
	{
		program->sprite_position.y -= 1;
		frame = 0;
	}
	mlx_put_image_to_window(program->mlx, \
							program->window.reference, \
							program->sprite.reference, \
							program->sprite_position.x, \
							program->sprite_position.y);
	return (0);
}

void	ft_update_coins(t_program *program)
{
	int			y;
	static int	num_sprite;
	t_sprite	coin_sprite;

	if (num_sprite >= 0 && num_sprite < 32)
	{
		num_sprite++;
		if (num_sprite % 2 == 0)
			coin_sprite = ft_create_coin_sprite(program, num_sprite);
		else
			coin_sprite = ft_create_coin_sprite(program, num_sprite - 1);
	}
	else
		num_sprite = 0;
	y = -1;
	while (program->map->ber[++y])
	{
		ft_put_coin_sprite(program, coin_sprite, num_sprite, y);
	}
}

void	ft_put_coin_sprite(t_program *program, t_sprite coin_sprite,
							int num_sprite, int y)
{
	int	x;

	x = 0;
	while (program->map->ber[y][x])
	{
		if (program->map->ber[y][x] == 'C')
		{
			mlx_put_image_to_window(program->mlx,
				program->window.reference,
				program->floor.reference, x * 64, y * 64);
			if (num_sprite <= 1)
				mlx_put_image_to_window(program->mlx,
					program->window.reference,
					program->coin.reference, x * 64, y * 64);
			else
				mlx_put_image_to_window(program->mlx,
					program->window.reference,
					coin_sprite.reference, x * 64, y * 64);
		}
		x++;
	}
}

t_sprite	ft_create_coin_sprite(t_program *program, int num_sprite)
{
	t_sprite	coin_sprite;

	if (num_sprite == 2)
		ft_create_sprite(program, &coin_sprite, "sprites/coin1.xpm");
	if (num_sprite == 4)
		ft_create_sprite(program, &coin_sprite, "sprites/coin2.xpm");
	if (num_sprite == 6)
		ft_create_sprite(program, &coin_sprite, "sprites/coin3.xpm");
	if (num_sprite == 8)
		ft_create_sprite(program, &coin_sprite, "sprites/coin4.xpm");
	if (num_sprite == 10)
		ft_create_sprite(program, &coin_sprite, "sprites/coin5.xpm");
	if (num_sprite == 12)
		ft_create_sprite(program, &coin_sprite, "sprites/coin6.xpm");
	if (num_sprite == 14)
		ft_create_sprite(program, &coin_sprite, "sprites/coin7.xpm");
	if (num_sprite > 14)
		return (ft_create_coin_sprite_2(program, num_sprite));
	return (coin_sprite);
}

t_sprite	ft_create_coin_sprite_2(t_program *program, int num_sprite)
{
	t_sprite	coin_sprite;

	if (num_sprite == 16)
		ft_create_sprite(program, &coin_sprite, "sprites/coin8.xpm");
	if (num_sprite == 18)
		ft_create_sprite(program, &coin_sprite, "sprites/coin9.xpm");
	if (num_sprite == 20)
		ft_create_sprite(program, &coin_sprite, "sprites/coin10.xpm");
	if (num_sprite == 22)
		ft_create_sprite(program, &coin_sprite, "sprites/coin11.xpm");
	if (num_sprite == 24)
		ft_create_sprite(program, &coin_sprite, "sprites/coin12.xpm");
	if (num_sprite == 26)
		ft_create_sprite(program, &coin_sprite, "sprites/coin13.xpm");
	if (num_sprite == 28)
		ft_create_sprite(program, &coin_sprite, "sprites/coin14.xpm");
	if (num_sprite == 30)
		ft_create_sprite(program, &coin_sprite, "sprites/coin15.xpm");
	if (num_sprite == 32)
		ft_create_sprite(program, &coin_sprite, "sprites/coin16.xpm");
	return (coin_sprite);
}
