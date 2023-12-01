/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:29:27 by panger            #+#    #+#             */
/*   Updated: 2023/12/01 18:01:38 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	*set_fd_to_use(int *fd, int fd_in, int fd_out)
{
	fd[0] = fd_in;
	fd[1] = fd_out;
}
int		command_exec(char *cmd, int p[2], int fd[2], char **env)
{
	char	**args;
	char	*path;

	if (fd[IN] == -1 || fd[OUT] == -1)
		exit(EXIT_FAILURE);
	dup2(fd[IN], STDIN_FILENO);
	dup2(fd[OUT], STDOUT_FILENO);
	args = ft_split(cmd, " \t\v\n\f\r");
	path = find_path(cmd, env);
	execve(path, args, env);
	perror("pipex");
	exit(EXIT_FAILURE);
}

int		command_receiver(int nb_cmd, char **cmds, char **env, int *fd_in_and_out)
{
	int	p[2];
	int fd_to_use[2];
	int	pid;
	int	i;

	i = 0;
	while (i < nb_cmd)
	{
		pipe(p);
		if (i == 0)
			set_fd_to_use(fd_to_use, fd_in_and_out[IN], p[WRITE]);
		else if (i == nb_cmd)
			set_fd_to_use(fd_to_use, fd_to_use[IN], fd_in_and_out[OUT]);
		else
			set_fd_to_use(fd_to_use, fd_to_use[IN], p[WRITE]);	
		pid = fork();
		if (pid == 0)
			command_exec(cmds[i], p, fd_to_use, env);
		close(p[READ]);
		close(fd_to_use[IN]);
		close(fd_to_use[OUT]);
		fd_to_use[IN] = p[READ];
		i++;
	}
	return (0);
}
