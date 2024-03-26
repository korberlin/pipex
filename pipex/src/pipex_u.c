/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:00:25 by gkoksal           #+#    #+#             */
/*   Updated: 2024/03/25 14:57:32 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_open(char **argv, int read_write)
{
	int	fd;

	if (read_write == 0)
	{
		if (access(argv[1], F_OK) != 0)
			exit_error(4);
		if (access(argv[1], R_OK) != 0)
			exit_error(5);
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			exit_error(4);
	}
	else
	{
		if (access(argv[4], F_OK) == 0 && access(argv[4], W_OK) != 0)
			exit_error(6);
		fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
		if (fd < 0)
			exit_error(4);
	}
	return (fd);
}

void	ft_free(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

char	*ft_parse(char **envp)
{
	char	*path;
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (envp[++i])
	{
		j = 0;
		while (envp[i][j] && envp[i][j] != '=')
			j++;
		path = ft_substr(envp[i], 0, j);
		if (ft_strncmp("PATH", path, 4) == 0)
		{
			free(path);
			return (envp[i] + j + 1);
		}
		free(path);
	}
	return (NULL);
}

char	*ft_path(char *cmd, char **envp)
{
	char	**full_path;
	char	*path;
	char	**p_name;
	char	*exec;
	int		i;

	full_path = ft_split(ft_parse(envp), ':');
	p_name = ft_split(cmd, ' ');
	i = -1;
	while (full_path[++i])
	{
		path = ft_strjoin(full_path[i], "/");
		exec = ft_strjoin(path, p_name[0]);
		free(path);
		if (access(exec, X_OK | F_OK) == 0)
		{
			ft_free(p_name);
			ft_free(full_path);
			return (exec);
		}
		free(exec);
	}
	ft_free(full_path);
	ft_free(p_name);
	return (ft_strdup(cmd));
}

void	exit_error(int i)
{
	if (i == 1)
		write(2, "Usage: ./pipex infile cmd cmd outfile\n", 39);
	if (i == 2)
		write(2, "An error ocurred with opening pipe.\n", 37);
	if (i == 3)
		write(2, "An error ocurred while creating fork\n", 38);
	if (i == 4)
		write(2, "no such file or directory\n", 27);
	if (i == 5)
		write(2, "Permission denied (Read).\n", 27);
	if (i == 6)
		write(2, "Permission denied (Write).\n", 27);
	exit(1);
}
