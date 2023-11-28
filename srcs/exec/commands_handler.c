/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:16:31 by panger            #+#    #+#             */
/*   Updated: 2023/11/28 16:44:04 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int command_executer(char *cmd, char **env, int p[2], int fd2)
{
	char	**args;
	char	*path;
	int		stdout_fd;

	close(p[1]);
	stdout_fd = dup(1);
	dup2(p[0], STDIN_FILENO);
	close(p[0]);
	args = ft_split(cmd, " \t\v\n\f\r");
	path = find_path(cmd, env);
	dup2(fd2, STDOUT_FILENO);
	execve(path, args, env);
	dup2(stdout_fd, 1);
	if (errno == EFAULT)
		ft_printf("pipex: command not found: %s\n", cmd);
	else
		ft_printf("pipex: failed to execute a command: %s\n", cmd);
	exit(EXIT_FAILURE);
}

int	get_fd(char **argv, int argc)
{
	int		fd2;

	fd2 = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (fd2 == -1)
		ft_printf("pipex: %s: %s\n", strerror(errno), argv[argc - 1]);
	return (fd2);
}

void	parent_process(int p[2], char **argv, int argc, int i)
{
	int 	test;
	char	buff[2048];
	char	*path;
	int		fd;

	if (i > 1)
		path = argv[argc - 1];
	else
		path = argv[0];
	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_printf("pipex: %s: %s\n", strerror(errno), path);
	close(p[0]);
	while ((test = read(fd, buff, 2048)) > 0)
		write(p[1], buff, test);
	close(p[1]);
	close(fd);
}

int command_receiver(char **argv, char **env, int argc)
{
	int		i;
	int		status;
	int		p[2];

	i = 1;
	while (i < argc - 1)
	{
		pipe(p);
		pid_t pid = fork();
		if (pid == 0)
		{
			command_executer(argv[i], env, p, get_fd(argv, argc));
		}
		else
		{
			parent_process(p, argv, argc, i);
			waitpid(pid, &status, 0);
		}
		i++;
	}
	return (0);
}
