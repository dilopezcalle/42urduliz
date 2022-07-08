/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 13:00:12 by dilopez-          #+#    #+#             */
/*   Updated: 2022/07/08 18:25:26 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>

// ========== STRUCTURES ==========
typedef struct s_philo
{
	int				id;
	int				fork;
	struct s_philo	*left;
	struct s_philo	*right;
}			t_philo;

typedef struct s_data
{
	int				num_philos;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				num_limit_eats;
	t_philo 		*lst_philo;
	
}			t_data;

// ========== PHILO ==========
void				ft_philo(int argc, char *argv[]);
void				ft_get_args(t_data *data, int argc, char *argv[]);
void				ft_get_philos(t_data *data);

// ========== UTILS ==========
void				ft_usleep(long milisecons);

#endif