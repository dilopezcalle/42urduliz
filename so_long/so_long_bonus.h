/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 12:54:22 by dilopez-          #+#    #+#             */
/*   Updated: 2022/07/05 15:23:04 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "srcs/get_next_line/get_next_line.h"
# include "minilibx/mlx.h"

// ========== structures ==========
typedef struct s_map
{
	char		**ber;
	int			width;
	int			height;
}				t_map;

typedef struct s_position
{
	int			x;
	int			y;
}				t_position;

typedef struct s_window
{
	void		*reference;
	t_position	size;
}				t_window;

typedef struct s_sprite
{
	void			*reference;
	char			*pixels;
	int				bits_per_pixel;
	int				line_size;
	int				endian;
	t_position		size;
	struct s_sprite	*next;
}				t_sprite;

typedef struct s_program
{
	void		*mlx;
	t_map		*map;
	t_window	window;
	t_sprite	wall;
	t_sprite	floor;
	t_sprite	coin;
	t_sprite	exit;
	t_sprite	thorn;
	t_sprite	sprite;
	t_position	sprite_position;
	int			movements;
	int			coins;
}				t_program;

// ========== so_long ==========
void			ft_so_long(char *map);
int				ft_exit_program(void *param);
void			ft_exit_program_error(char *str);
void			ft_print_perror(char *str, int code);

// ========== map ==========
void			ft_get_map(t_program *program, char *ber);
int				ft_check_map(t_program *program);
int				ft_check_chars_map(char *row, int width, int pos_row);
void			ft_free_map(t_map **map);

// ========== sprites ==========
void			ft_put_sprites(t_program *program);
void			ft_create_sprite(t_program *program, t_sprite *sprite,
					char *path);
void			ft_put_chars_sprites(t_program *program, int x, int y);

// ========== hooks ==========
int				ft_press_key(int key, void *param);
void			ft_upgrade_sprites(t_program *program, int x, int y);

// ========== bonus ==========
int				ft_put_str_to_window(t_program *program);
void			ft_check_death_or_win(t_program *program);
int				ft_update_sprites(void *param);
void			ft_update_coins(t_program *program);
t_sprite		ft_create_coin_sprite(t_program *program, int num_sprite);
t_sprite		ft_create_coin_sprite_2(t_program *program, int num_sprite);
void			ft_put_coin_sprite(t_program *program, t_sprite coin_sprite,
					int num_sprite, int y);

// ========== libft ==========
void			*ft_memset(void *b, int c, size_t len);
char			**ft_split(char const *s, char c);
char			*ft_split_check_chars(char const *s, char c, int row);
int				ft_split_check_rows(char const *s, char c);
char			*ft_itoa(int n);

#endif