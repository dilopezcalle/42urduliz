/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 13:00:12 by dilopez-          #+#    #+#             */
/*   Updated: 2022/07/30 18:25:52 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>

// ========== STRUCTURES ==========
typedef struct s_philo
{
	pthread_t		thread;
	int				id;	
	int				fork;
	int				num_forks;
	int				*taken_fork_1;
	int				*taken_fork_2;
	long			last_eat;
	struct s_philo	*left;
	struct s_philo	*right;
}					t_philo;

typedef struct s_data
{
	long			
	int				num_philos;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				num_limit_eats;
	int				print_death;
	t_philo 		*lst_philo;
	struct timeval	init_time; 
	pthread_mutex_t	mutex;
	pthread_mutex_t	mutex2;
}					t_data;

// ========== PHILO ==========
void				ft_philo(int argc, char *argv[]);
void				ft_get_args(t_data *data, int argc, char *argv[]);
void				ft_get_philos(t_data *data);
void				*ft_philo_states(void *param);

// ========== UTILS ==========
void					ft_msleep_for_eat(long milisecons, t_philo *philo, t_data *data);
void					ft_msleep(long milisecons, t_philo *philo, t_data *data);
long				ft_timecomp(struct timeval timer);

#endif