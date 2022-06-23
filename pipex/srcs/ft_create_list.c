/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 09:42:27 by dilopez-          #+#    #+#             */
/*   Updated: 2022/06/18 15:18:01 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"
#include <unistd.h>
#include <stdio.h>

t_data	*ft_create_list(int argc, char *argv[], char **paths)
{
	t_data	*command_list;
	t_data	*new;
	int		i;

	command_list = 0;
	i = 1;
	while (i < argc - 1)
	{
		new = ft_calloc(1, sizeof(t_data));
		if (!new)
			exit(2);
		new->flags = ft_split(argv[i], ' ');
		new->path = ft_get_command_path((new->flags)[0], paths);
		new->next = 0;
		ft_lstadd(&command_list, new);
		i++;
	}
	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
	return (command_list);
}

char	*ft_get_command_path(char *command, char **paths)
{
	char	*command_path;
	char	*path;
	char	*temp;
	int		i;

	i = 0;
	path = 0;
	while (paths[i])
	{
		command_path = ft_strjoin("/", command);
		temp = ft_strjoin(paths[i], command_path);
		if (access(temp, F_OK) == 0)
			path = temp;
		else
			free(temp);
		free(command_path);
		i++;
	}
	return (path);
}

void	ft_lstadd(t_data **lst, t_data *new)
{
	t_data	*last_list;

	if (*lst == 0)
	{
		*lst = new;
		return ;
	}
	last_list = *lst;
	while (last_list->next != NULL)
		last_list = last_list->next;
	last_list->next = new;
}
