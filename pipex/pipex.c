/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 12:19:57 by dilopez-          #+#    #+#             */
/*   Updated: 2022/06/12 10:42:04 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	if (argc >= 5)
		ft_pipex(argc - 1, argv + 1, envp);
	else
		ft_exit_program(0, 22);
	return 0;
}

void	ft_pipex(int argc, char *argv[], char *envp[])
{
	t_data	*command_list;
	char	**paths;
	int		status;
	int		i;

	paths = ft_get_paths(envp);
	command_list = ft_create_list(argc, argv, paths);
	status = ft_check_list(argc, argv, command_list) != 0;
	if (status != 0)
		ft_exit_program(command_list, status);
	ft_create_pipe(command_list, argv, argc, envp);
	ft_exit_program(command_list, 0);
}

void	ft_exit_program(t_data *command_list, int status)
{
	t_data	*aux;
	int		i;

	while (command_list)
	{
		i = -1;
		aux = command_list;
		command_list = command_list->next;
		free(aux->path);
		while ((aux->flags)[++i])
			free((aux->flags)[i]);
		free(aux->flags);
		free(aux);
	}
	if (status)
	{
		errno = status;
		perror("Error");
	}
	exit(status);
}

void	ft_print_list(t_data *command_list)
{
	int	i;

	while (command_list)
	{
		i = 0;
		printf("%s\n", command_list->path);
		/*
		while ((command_list->flags)[i])
		{
			printf("%s\n", (command_list->flags)[i]);
			i++;
		}
		*/
		command_list = command_list->next;
	}
}
