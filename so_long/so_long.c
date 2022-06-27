/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 12:54:41 by dilopez-          #+#    #+#             */
/*   Updated: 2022/06/27 16:40:37 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	main(int argc, char *argv[])
{
	if (argc == 2)
		ft_so_long(argv[1]);
	else
	{
		ft_print_perror("Error", 22);
		exit(2);
	}
	exit(0);
	return (0);
}

void	ft_so_long(char *argv)
{
	t_map		*map;
	t_program	program;
	
	ft_get_map(&map, argv);
	program.mlx = mlx_init();

	program.window.reference = mlx_new_window(program.mlx, map->width * 64, map->height * 64, "Hello");
	program.window.size.x = map->width * 64;
	program.window.size.y = map->height * 64;
	mlx_hook(program.window.reference, 17, 0, ft_exit_program, 0);

	program.sprite.reference = mlx_xpm_file_to_image(program.mlx, "sprites/cube.xpm", &program.sprite.size.x, &program.sprite.size.y);
	program.sprite.pixels = mlx_get_data_addr(program.sprite.reference, &program.sprite.bits_per_pixel, &program.sprite.line_size, &program.sprite.endian);

	mlx_put_image_to_window(program.mlx, program.window.reference,
		program.sprite.reference, program.sprite_position.x, program.sprite_position.y);

	mlx_key_hook(program.window.reference, *ft_press_key, &program);

	mlx_loop(program.mlx);

	ft_free_map(&map);
}

int		ft_press_key(int key, void *param)
{
	t_program *program = (t_program *)param;

	mlx_clear_window(program->mlx, program->window.reference);

	if (key == 0)
		program->sprite_position.x -= program->sprite.size.x;
	else if (key == 1)
		program->sprite_position.y += program->sprite.size.y;
	else if (key == 2)
		program->sprite_position.x += program->sprite.size.x;
	else if (key == 13)
		program->sprite_position.y -= program->sprite.size.y;

	mlx_put_image_to_window(program->mlx, program->window.reference,
		program->sprite.reference, program->sprite_position.x, program->sprite_position.y);	

	return (0);
}

void	ft_print_perror(char *str, int code)
{
	errno = code;
	perror(str);
}

void	ft_exit_program_error(char *str)
{
	printf("%s\n", str);
	exit(2);
}

int	ft_exit_program()
{
	//ft_free_map(map);
	exit(0);
}
