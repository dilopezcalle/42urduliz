/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 08:01:25 by dilopez-          #+#    #+#             */
/*   Updated: 2022/06/12 09:21:35 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

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

int	ft_check_list(int argc, char *argv[], t_data *command_list)
{
	int	i;
	int	fd;

	fd = open(argv[0], O_RDONLY);
	if (fd < 0)
	{
		if (access(argv[0], F_OK) != 0)
			return (2);
		else
			return (13);
	}
	close(fd);
	fd = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0777);
	if (fd < 0)
		return (13);
	close(fd);
	i = 1;
	while (i < argc - 1)
	{
		if (!command_list->path)
			return (1);
		command_list = command_list->next;
		i++;
	}
	if (access(argv[0], R_OK) != 0)
		return (1);
	if (access(argv[argc - 1], W_OK))
		return (1);
	return (0);
}
