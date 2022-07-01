/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 12:54:41 by dilopez-          #+#    #+#             */
/*   Updated: 2022/07/01 17:28:57 by dilopez-         ###   ########.fr       */
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
	t_program	program;

	ft_get_map(&program, argv);
	program.mlx = mlx_init();
	program.window.reference = mlx_new_window(program.mlx, program.map->width
			* 64, program.map->height * 64, "so_long");
	program.window.size.x = program.map->width * 64;
	program.window.size.y = program.map->height * 64;
	mlx_hook(program.window.reference, 17, 0, ft_exit_program, 0);
	ft_put_sprites(&program);
	mlx_key_hook(program.window.reference, *ft_press_key, &program);
	mlx_loop(program.mlx);
	ft_free_map(&program.map);
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

//ft_free_map(map);
int	ft_exit_program(void)
{
	exit(0);
}
