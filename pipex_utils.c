#include "pipex.h"

void	error_msg(char *str)
{
	perror(str);
	exit(1);
}

void	ft_free(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char *find_path(char *cmd, char **env)
{
	int	i;
	char *path;
	char *part_path;
	char **full_path;

	i = 0;
	while (ft_strnstr(env[i], "PATH", 4) == 0)
		i++;
	full_path = ft_split(env[i] + 5, ':');
	i = 0;
	while (full_path[i])
	{
		part_path = ft_strjoin(full_path[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK | X_OK) == 0)
		{
			//ft_free(full_path);
			return (path);
		}
		free(path);
		i++;
	}

	ft_free(full_path);
	return (0);
}

void ft_execve(char *argv, char **env)
{
	int result;
	char *path;
	char **cmd;

	cmd = ft_split(argv, ' ');	   // cmd1 과 cmd2 분리  + grep a
	path = find_path(cmd[0], env); // bin/wc 등 path를 찾기 위해서 , 기본 path 확인, 명령인지
	if (path)
	{
		result = execve(path, cmd, env);
		free(path);
	}
	ft_free(cmd);
	if ((!path) || result == -1)
		error_msg("error");
}
