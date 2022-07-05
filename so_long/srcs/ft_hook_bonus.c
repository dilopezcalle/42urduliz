/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 07:47:09 by dilopez-          #+#    #+#             */
/*   Updated: 2022/07/05 15:27:55 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"
#include <stdio.h>

int	ft_press_key(int key, void *param)
{
	t_program	*program;
	int			move;
	int			x;
	int			y;

	program = (t_program *)param;
	move = 0;
	x = program->sprite_position.x / 64;
	y = program->sprite_position.y / 64;
	if (key == 0 && ((program->map)->ber)[y][x - 1] != '1' && ++move)
		program->sprite_position.x -= program->sprite.size.x;
	else if (key == 1 && ((program->map)->ber)[y + 1][x] != '1' && ++move)
		program->sprite_position.y += program->sprite.size.y;
	else if (key == 2 && ((program->map)->ber)[y][x + 1] != '1' && ++move)
		program->sprite_position.x += program->sprite.size.x;
	else if (key == 13 && ((program->map)->ber)[y - 1][x] != '1' && ++move)
		program->sprite_position.y -= program->sprite.size.y;
	else if (key == 53)
		ft_exit_program(program);
	if (!move)
		return (0);
	ft_check_death_or_win(program);
	ft_upgrade_sprites(program, x, y);
	return (0);
}

void	ft_check_death_or_win(t_program *program)
{
	if (((program->map)->ber)[program->sprite_position.y / 64]
		[program->sprite_position.x / 64] == 'T')
	{
		printf("\n\x1B[31mYOU'RE DEAD\n\n");
		ft_exit_program(program);
	}
	if (((program->map)->ber)[program->sprite_position.y / 64]
		[program->sprite_position.x / 64] == 'E' && program->coins == 0)
	{
		printf("\n\x1B[32mYOU WIN\n\n");
		ft_exit_program(program);
	}
}

void	ft_upgrade_sprites(t_program *program, int x, int y)
{
	mlx_put_image_to_window(program->mlx, program->window.reference, \
							program->wall.reference, 64, 0);
	mlx_put_image_to_window(program->mlx, program->window.reference, \
							program->wall.reference, 0, 0);
	if (!ft_put_str_to_window(program))
		ft_exit_program(program);
	mlx_put_image_to_window(program->mlx, program->window.reference, \
							program->floor.reference, x * 64, y * 64);
	if (((program->map)->ber)[y][x] == 'C')
		(program->coins)--;
	if (((program->map)->ber)[y][x] == 'E')
		mlx_put_image_to_window(program->mlx, program->window.reference, \
								program->exit.reference, x * 64, y * 64);
	else
		((program->map)->ber)[y][x] = '0';
	printf("Movement: %d\n", program->movements);
	mlx_put_image_to_window(program->mlx, program->window.reference, \
			program->sprite.reference, program->sprite_position.x, \
			program->sprite_position.y);
}

int	ft_put_str_to_window(t_program *program)
{
	char	*movement;
	char	*num_movement;

	movement = ft_substr("Movements: ", 0, 11);
	if (!movement)
		return (0);
	num_movement = ft_itoa(++(program->movements));
	movement = ft_strjoin(movement, num_movement);
	mlx_string_put(program->mlx, program->window.reference, \
					19, 36, -255, movement);
	free(num_movement);
	free(movement);
	return (1);
}
