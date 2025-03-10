/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giuliagalizoni <giuliagalizoni@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:09:57 by ggalizon          #+#    #+#             */
/*   Updated: 2025/03/05 10:26:21 by giuliagaliz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <errno.h>
# include <fcntl.h>
# include "../../libft/libft.h"

typedef struct s_pipex
{
	int		fd[2];
	int		pipe;
	int		pid;
	char	**cmd_arr;
	char	*path;

}	t_pipex;

int		check_arguments(int argc);
char	*get_path(char *cmd, char **env);
void	free_arr(char **arr);
void	cleanup(t_pipex *pipex);

#endif
