/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 08:01:25 by dilopez-          #+#    #+#             */
/*   Updated: 2022/06/15 12:49:02 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"
#include <fcntl.h>
#include <unistd.h>

int	ft_check_infile(char *argv[])
{
	int	fd;

	fd = open(argv[0], O_RDONLY);
	if (fd < 0)
	{
		if (access(argv[0], F_OK) != 0)
		{
			ft_print_perror(argv[0], 2);
			exit(2);
		}
		else
		{
			ft_print_perror(argv[0], 13);
			exit(2);
		}
	}
	close(fd);
	return (0);
}

int	ft_check_outfile(int argc, char *argv[])
{
	int	fd;

	fd = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd < 0)
	{
		if (access(argv[argc - 1], F_OK) == 0)
		{
			ft_print_perror(argv[argc - 1], 13);
			exit(2);
		}
		exit(2);
	}
	close(fd);
	return (0);
}

char	**ft_get_paths(char *envp[])
{
	int		i;
	char	**paths;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH", 4) != 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	return (paths);
}

int	ft_check_list(int argc, t_data *command_list)
{
	int	i;

	i = 1;
	while (i < argc - 1)
	{
		if (!command_list->path)
			return (3);
		command_list = command_list->next;
		i++;
	}
	return (0);
}
