/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaaaaran <aaaaaran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:47:00 by arlee             #+#    #+#             */
/*   Updated: 2023/11/14 13:08:54 by aaaaaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void parent_process(char **argv, char **envp, int *fd)
{
	int open_fd;

	open_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (open_fd == -1)
		error_msg("error");
	close(fd[1]);
	dup2(open_fd, 1);
	dup2(fd[0], 0);
	
	ft_execve(argv[3], envp); // execute PATH
	close(open_fd);
}

void child_process(char **argv, char **envp, int *fd)
{
	int open_fd;

	open_fd = open(argv[1], O_RDONLY, 0777);
	if (open_fd == -1)
		error_msg("error");
	close(fd[0]);
	dup2(open_fd, 0);
	dup2(fd[1], 1);
	
	ft_execve(argv[2], envp);
	close(open_fd);
}

int main(int argc, char **argv, char **envp)
{
	int fd[2];
	pid_t pid;
	// char **full_path;
	// char *part_path;

	// int i = 0;
	// while(envp[i])
	// {
	// 	printf("%d,:  %s\n", i, envp[i]);
	// 	i++;
	// }
	// i = 0;
	// while (ft_strnstr(envp[i], "PATH=", 5) == 0)
	// 	i++;
	// full_path = ft_split(envp[i] + 5, ':');
	// i = 0;
	// while (full_path[i])
	// {	
	// 	part_path = ft_strjoin(full_path[i], "/");
	// 	printf("part_path::: %s\n", part_path);
	// 	i++;
	// }




	if (argc != 5)
	{
		ft_putstr_fd("./pipex infile cmd cmd outfile\n", 2);
		//exit(1);
	}
	if (pipe(fd) == -1)
		exit(1);
	pid = fork();
	if (pid == -1)
		error_msg("fork");
	if (!pid)
		child_process(argv, envp, fd);
	//waitpid(pid, NULL, WNOHANG);
	parent_process(argv, envp, fd);
	return (0);
}
