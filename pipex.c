/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlee <arlee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:47:00 by arlee             #+#    #+#             */
/*   Updated: 2023/11/09 20:51:36 by arlee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void parent_process(char **argv, char **env, int *fd)
{
	int open_fd;

	open_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (open_fd == -1)
		error_msg("error");
	dup2(open_fd, 1);
	dup2(fd[0], 0);
	close(fd[1]);
	ft_execve(argv[3], env);
	close(open_fd);
}

void child_process(char **argv, char **env, int *fd)
{
	int open_fd;

	open_fd = open(argv[1], O_RDONLY, 0777);
	if (open_fd == -1)
		error_msg("error");
	dup2(open_fd, 0);
	dup2(fd[1], 1);
	close(fd[0]);
	ft_execve(argv[2], env);
	close(open_fd);
}

int main(int argc, char **argv, char **env)
{
	int fd[2];
	pid_t pid;

	if (argc != 5)
	{
		ft_putstr_fd("./pipex infile cmd cmd outfile\n", 2);
		//exit(1);
	}
	if (pipe(fd) == -1)
		error_msg("pipe");
	pid = fork();
	if (pid == -1)
		error_msg("fork");
	if (!pid)
		child_process(argv, env, fd);
	waitpid(pid, NULL, WNOHANG);
	parent_process(argv, env, fd);
	return (0);
}
