/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 12:19:57 by dilopez-          #+#    #+#             */
/*   Updated: 2022/06/18 09:13:48 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>
#include <errno.h>

int	main(int argc, char *argv[], char *envp[])
{
	if (argc == 5)
		ft_pipex(argc - 1, argv + 1, envp);
	else
	{
		ft_print_perror("Error", 22);
		ft_exit_program(0, 2);
	}
	return (0);
}

void	ft_pipex(int argc, char *argv[], char *envp[])
{
	t_data	*command_list;
	char	**paths;
	int		status;

	if (ft_check_infile(argv) != 0 || ft_check_outfile(argc, argv) != 0)
		exit(2);
	paths = ft_get_paths(envp);
	command_list = ft_create_list(argc, argv, paths);
	status = ft_check_list(argc, command_list);
	if (status != 0)
	{
		ft_print_perror("access", status);
		ft_exit_program(command_list, 2);
	}
	ft_create_pipe(command_list, argv, argc, envp);
	ft_exit_program(command_list, 0);
}

void	ft_print_perror(char *str, int code)
{
	errno = code;
	perror(str);
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
	exit(status);
}
