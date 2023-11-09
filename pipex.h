/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlee <arlee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:47:03 by arlee             #+#    #+#             */
/*   Updated: 2023/11/09 20:47:12 by arlee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "libft/libft.h"


void    child_process(char **argv, char **env, int *fd);
void    parent_process(char **argv, char **env, int *fd);
void    free_cmd(char **cmd);
char    *find_path(char *cmd, char **env);
void    ft_execve(char *argv, char **env);
void    error_msg(char *str);

#endif