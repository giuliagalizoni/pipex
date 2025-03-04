/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscode <vscode@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:09:02 by ggalizon          #+#    #+#             */
/*   Updated: 2025/03/04 10:47:40 by vscode           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	check_arguments(int argc, char **argv)
{
	if (argc != 5)
	{
		ft_printf("Error: wrong number of arguments\n");
		exit(1);
		return (1);
	}
	return (0);
}

void	free_arr(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	arr = NULL;
}

char	*get_command(char **paths, char *cmd)
{
	char	*full_cmd;
	char	*temp;
	int		i;

	i = 0;
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], "/");
		if (!temp)
			return (NULL);
		full_cmd = ft_strjoin(temp, cmd);
		free(temp);
		if (access(full_cmd, X_OK) == 0)
		{
			free_arr(paths);
			return (full_cmd);
		}
		free(full_cmd);
		i++;
	}
	free_arr(paths);
	return (NULL);
}

char	*get_path(char *cmd, char **env)
{
	char	*path_env;
	char	**paths;

	while (*env)
	{
		if (ft_strncmp(*env, "PATH=", 5) == 0)
		{
			path_env = *env + 5;
			paths = ft_split(path_env, ':');
			if (!paths)
				return (NULL);
			return (get_command(paths, cmd));
			free_arr(paths);
		}
		env++;
	}
	return (NULL);
}

void	cleanup(t_pipex *pipex)
{
	if (pipex->fd[0])
		close(pipex->fd[0]);
	if (pipex->fd[1])
		close(pipex->fd[1]);
	if (pipex->cmd_arr)
	{
		free_arr(pipex->cmd_arr);
		pipex->cmd_arr = NULL;
	}
	if (pipex->path)
	{
		free(pipex->path);
		pipex->path = NULL;
	}
}
