/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 07:47:09 by dilopez-          #+#    #+#             */
/*   Updated: 2022/07/01 19:14:59 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_press_key(int key, void *param)
{
	t_program	*program;
	t_image		floor;
	t_image		exit;
	int			move;
	int			x;
	int			y;

	printf("key: %d\n", key);
	program = (t_program *)param;
	move = 0;
	x = program->sprite_position.x / 64;
	y = program->sprite_position.y / 64;
	ft_create_sprite(program, &floor, "sprites/floor.xpm");
	ft_create_sprite(program, &exit, "sprites/exit.xpm");
	if (key == 0 && ((program->map)->ber)[y][x - 1] != '1' && ++move)
		program->sprite_position.x -= program->sprite.size.x;
	else if (key == 1 && ((program->map)->ber)[y + 1][x] != '1' && ++move)
		program->sprite_position.y += program->sprite.size.y;
	else if (key == 2 && ((program->map)->ber)[y][x + 1] != '1' && ++move)
		program->sprite_position.x += program->sprite.size.x;
	else if (key == 13 && ((program->map)->ber)[y - 1][x] != '1' && ++move)
		program->sprite_position.y -= program->sprite.size.y;
	else if (key == 53)
		ft_exit_program();
	if (!move)
		return (0);
	mlx_put_image_to_window(program->mlx, program->window.reference, \
							floor.reference, x * 64, y * 64);
	if (((program->map)->ber)[y][x] == 'C')
		(program->coins)--;
	if (((program->map)->ber)[y][x] == 'E')
		mlx_put_image_to_window(program->mlx, program->window.reference, \
								exit.reference, x * 64, y * 64);
	else
		((program->map)->ber)[y][x] = 0;
	printf("Movement: %d\n", ++(program->movements));
	mlx_put_image_to_window(program->mlx, program->window.reference, \
			program->sprite.reference, program->sprite_position.x, \
			program->sprite_position.y);
	if (((program->map)->ber)[program->sprite_position.y / 64]
		[program->sprite_position.x / 64] == 'E' && program->coins == 0)
		ft_exit_program();
	return (0);
}
