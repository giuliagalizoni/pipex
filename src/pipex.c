/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalizon <ggalizon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:08:51 by ggalizon          #+#    #+#             */
/*   Updated: 2025/03/03 15:13:45 by ggalizon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"


int	execute(char *cmd, char **env)
{
	char	**cmd_arr;
	char	*path;

	cmd_arr = ft_split(cmd, ' ');
	if (!cmd_arr)
		return 1;
	path = get_path(cmd_arr[0], env);
	if (!path)
	{
		ft_printf("Error: command not found\n");
		return 1;
	}
	if (execve(path, cmd_arr, env) == -1)
	{
		ft_printf("Error: %s\n", strerror(errno));
		return 1;
	}
	return 0;
}

int child(int *fd, char **argv, char **env)
{
	int	fd_file;

	fd_file = open(argv[1], O_RDONLY);
	if (fd_file == -1)
	{
		ft_printf("Error: %s\n", strerror(errno));
		exit(1);
	}
	ft_printf("Im the child process\n");
	dup2(fd_file, 0);
	dup2(fd[1], 1);
	close(fd[0]);
	close(fd_file);
	close(fd[1]);
	execute(argv[2], env);
	return (0);
}

int	parent(int *fd, char **argv, char **env)
{
	int	fd_file;

	fd_file = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_file == -1)
	{
		ft_printf("Error: %s\n", strerror(errno));
		exit(1);
	}
	ft_printf("Im the parent process\n");
	dup2(fd[0], 0);
	dup2(fd_file, 1);
	close(fd[1]);
	close(fd[0]);
	close(fd_file);
	if (!execute(argv[3], env))
	{
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
int	main(int argc, char** argv, char **env)
{
	int	fd[2];
	int pid;

	check_arguments(argc, argv);
	if (pipe(fd) == -1) {
		ft_printf("An error occurred"); //error management
		return 1;
	}
	pid = fork();
	if (pid == 0)
		child(fd, argv, env);
	else
	{
		waitpid(pid, NULL, 0);
		parent(fd, argv, env);
	}
	return 0;
}
