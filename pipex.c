/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaaaaran <aaaaaran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:47:00 by arlee             #+#    #+#             */
/*   Updated: 2023/11/20 16:42:15 by aaaaaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parent_process(char **argv, char **envp, int *fd)
{
	int	open_fd;

	open_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (open_fd == -1)
		error_msg("error");
	dup2(fd[0], 0);
	close(fd[0]);
	dup2(open_fd, 1);
	close(fd[1]);
	close(open_fd);
	ft_execve(argv[3], envp);
}

void	child_process(char **argv, char **envp, int *fd)
{
	int	open_fd;

	open_fd = open(argv[1], O_RDONLY, 0777);
	if (open_fd == -1)
		error_msg("error");
	//close(fd[0]);
	dup2(fd[1], 1);
	close(fd[1]);
	dup2(open_fd, 0);
	
	close(fd[0]);
	close(open_fd);
	//dup2(fd[1], 1);
	ft_execve(argv[2], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (argc != 5)
	{
		ft_putstr_fd("./pipex infile cmd1 cmd2 outfile\n", 2);
		exit(1);
	}
	if (pipe(fd) == -1)
		error_msg("pipe");
	pid = fork();
	if (pid == -1)
		error_msg("fork");
	if (pid == 0)
		child_process(argv, envp, fd);
	waitpid(pid, NULL, WNOHANG);
	parent_process(argv, envp, fd);
	return (0);
}
