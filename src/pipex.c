/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscode <vscode@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:08:51 by ggalizon          #+#    #+#             */
/*   Updated: 2025/03/04 10:13:07 by vscode           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	execute(t_pipex *pipex, char *cmd, char **env)
{
	pipex->cmd_arr = ft_split(cmd, ' ');
	if (!pipex->cmd_arr)
		return (1);
	pipex->path = get_path(pipex->cmd_arr[0], env);
	if (!pipex->path)
	{
		ft_printf("Error: command not found\n");
		return (1);
	}
	if (execve(pipex->path, pipex->cmd_arr, env) == -1)
	{
		cleanup(pipex);
		ft_printf("Error: %s\n", strerror(errno));
		return (1);
	}
	return (0);
}

int	child(t_pipex *pipex, char **argv, char **env)
{
	int	fd_file;

	fd_file = open(argv[1], O_RDONLY);
	if (fd_file == -1)
	{
		ft_printf("Error: %s\n", strerror(errno));
		exit(1);
	}
	dup2(fd_file, 0);
	dup2(pipex->fd[1], 1);
	close(pipex->fd[0]);
	close(fd_file);
	close(pipex->fd[1]);
	if (execute(pipex, argv[2], env))
	{
		cleanup(pipex);
		ft_printf("Error: %s\n", strerror(errno));
		exit(1);
	}
	return (0);
}

int	parent(t_pipex *pipex, char **argv, char **env)
{
	int	fd_file;

	fd_file = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_file == -1)
	{
		ft_printf("Error: %s\n", strerror(errno));
		exit(1);
	}
	dup2(pipex->fd[0], 0);
	dup2(fd_file, 1);
	close(pipex->fd[1]);
	close(pipex->fd[0]);
	close(fd_file);
	if (execute(pipex, argv[3], env))
	{
		cleanup(pipex);
		ft_printf("Error: %s\n", strerror(errno));
		exit(1);
	}
	return (0);
}

// MAIN
// initiate the fd
// initiate the pid
// check arguments
// create a pipe and check
// fork the process and check
// if the process is a child, call child()
// if the process is a parent, call parent()

// EXECUTION
// split the command
// get the path
// call execve and check
// if error, print error and cleanup

// fd[0] - read | fd[1] - write
int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;
	// int	fd[2];
	// int	pid;

	check_arguments(argc, argv);
	pipex.pipe = pipe(pipex.fd);
	if (pipex.pipe == -1)
	{
		ft_printf("An error occurred");
		return (1);
	}
	pipex.pid = fork();
	if (pipex.pid == 0)
		child(&pipex, argv, env);
	else
	{
		waitpid(pipex.pid, NULL, 0);
		parent(&pipex, argv, env);
	}
	return (0);
}
