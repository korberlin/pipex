/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:01:05 by gkoksal           #+#    #+#             */
/*   Updated: 2024/03/25 12:09:52 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exec(char **argv, char **envp, int cmd_number)
{
	char	**cmd;
	char	*path;

	if (cmd_number == 1)
		cmd = ft_split(argv[2], ' ');
	else
		cmd = ft_split(argv[3], ' ');
	path = ft_path(cmd[0], envp);
	if (execve(path, cmd, envp) == -1)
	{
		ft_free(cmd);
		free(path);
		write(2, "Command not found\n", 19);
		exit(127);
	}
}

void	child_first(char **argv, char **envp, int fd[])
{
	int	filed;

	close(fd[0]);
	filed = ft_open(argv, 0);
	dup2(filed, 0);
	dup2(fd[1], 1);
	close(fd[1]);
	close(filed);
	ft_exec(argv, envp, 1);
}

void	child_second(char **argv, char **envp, int fd[])
{
	int	filed;

	close(fd[1]);
	filed = ft_open(argv, 1);
	dup2(filed, 1);
	dup2(fd[0], 0);
	close(fd[0]);
	close(filed);
	ft_exec(argv, envp, 2);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (argc != 5)
		exit_error(1);
	if (pipe(fd) == -1)
		exit_error(2);
	pid = fork();
	if (pid == -1)
		exit_error(3);
	if (pid == 0)
		child_first(argv, envp, fd);
	child_second(argv, envp, fd);
}
