/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlee <arlee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:01:36 by aaaaaran          #+#    #+#             */
/*   Updated: 2023/11/23 16:14:34 by arlee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_msg(char *str)
{
	perror(str);
	exit(1);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char	*find_path(char *cmd, char **envp)
{
	int		i;
	char	*path;
	char	*part_path;
	char	**full_path;

	i = 0;
	while (ft_strnstr(envp[i], "PATH=", 5) == 0)
		i++;
	full_path = ft_split(envp[i] + 5, ':');
	i = 0;
	while (full_path[i])
	{
		part_path = ft_strjoin(full_path[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK | X_OK) == 0)
		{
			ft_free(full_path);
			return (path);
		}
		free(path);
		i++;
	}
	ft_free(full_path);
	return (NULL);
}

void	ft_execve(char *argv, char **envp)
{
	int		result;
	char	*path;
	char	**cmd;

	cmd = ft_split(argv, ' ');
	path = find_path(cmd[0], envp);
	if (path)
	{
		result = execve(path, cmd, envp);
		free(path);
		ft_free(cmd);
	}
	if ((!path) || result == -1)
	{
		ft_putstr_fd("command not found", 2);
		ft_free(cmd);
		exit(127);
	}
}
