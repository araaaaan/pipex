/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaaaaran <aaaaaran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:47:03 by arlee             #+#    #+#             */
/*   Updated: 2023/11/09 11:58:21 by aaaaaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft/libft.h"

void child_process(char **argv, char **env, int *fd);
void parent_process(char **argv, char **env, int *fd);
void free_cmd(char **cmd);
char *find_path(char *cmd, char **env);
void ft_execve(char *argv, char **env);

#endif