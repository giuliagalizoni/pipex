/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalizon <ggalizon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:09:02 by ggalizon          #+#    #+#             */
/*   Updated: 2025/03/03 15:38:19 by ggalizon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	check_arguments(int argc, char **argv)
{
	if (argc != 5)
	{
		ft_printf("Error: wrong number of arguments\n");
		exit(1);
		return 1;
	}
	return 0;
}

void free_paths(char **paths)
{
	int i;

	i = 0;
	while (paths[i])
		free(paths[i++]);
	free(paths);
}

char *get_command(char **paths, char *cmd)
{
	char *full_cmd;
	char *temp;
	int i;

	i = 0;
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], "/");
		if (!temp)
			return NULL;
		full_cmd = ft_strjoin(temp, cmd);
		free(temp);
		if (access(full_cmd, X_OK) == 0)
			return (free_paths(paths), full_cmd);
		free(full_cmd);
		i++;
	}
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
				return NULL;
			return get_command(paths, cmd);
			free_paths(paths);
		}
		env++;
	}
	return NULL;
}
