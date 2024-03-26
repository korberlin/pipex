/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:57:52 by gkoksal           #+#    #+#             */
/*   Updated: 2024/03/14 10:08:47 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>

int		ft_open(char **argv, int read_write);
void	ft_free(char **str);
char	*ft_parse(char **envp);
char	*ft_path(char *cmd, char **envp);
void	exit_error(int i);
void	ft_exec(char **argv, char **envp, int cmd_number);
void	child_first(char **argv, char **envp, int fd[]);
void	child_second(char **argv, char **envp, int fd[]);

#endif
