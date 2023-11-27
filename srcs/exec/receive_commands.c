/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:16:31 by panger            #+#    #+#             */
/*   Updated: 2023/11/27 19:07:53 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int command_executer(char *cmd, char **env)
{
	char	**args;
	char	**paths;
	char	*path;
	int		j;

	args = ft_split(cmd, " \t\v\n\f\r");
	paths = get_paths(env);
	j = 0;
	while (paths[j])
	{
		path = join_paths(paths[j++], args[0]);
		if (access(path, F_OK) != -1)
			break ;
		free(path);
	}
	freetab(paths);
	printf("path %s\n", path);
	fflush(stdout);
	int i = 0;
	while (args[i])
		printf("args %s\n", args[i++]);
	fflush(stdout);
	execve(path, args, env);
	return (0);
}

int command_receiver(char **argv, char **env, int argc)
{
	int		i;
	int		status;
	char	buff[64];
	int		fd1;
	int		fd2;
	int		p[2];

	fd1 = open(argv[0], O_RDONLY);
	fd2 = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0777);
	//pipe(p);
	printf("here");
	fflush(stdout);
	//dup2(fd2, 1);
	//dup2(p[0], 0);
	i = 1;
	int test = -1;
	while (test != 0)
	{
		printf("in loop\n");
		test = read(fd1, buff, 64);
		if (test == -1)
			break;
		buff[test] = '\0';
		write(1, buff, test);
		printf("test %d\n", test);
	}
	while (i < argc - 1)
	{
		pid_t pid = fork();
		if (pid == 0)
		{
			close (STDIN_FILENO);
			dup2(p[0], STDIN_FILENO);
			command_executer(argv[i], env);
		}
		else
		{
			/* int test = -1;
			close(p[0]);
			while (test != 0)
			{
				test = read(fd1, buff, 64);
				write(p[1], buff, 64);
			} */
			printf("Process Started\n");
			fflush(stdout);
			waitpid(pid, &status, 0);
			fflush(stdout);
			printf("Process ended\n");
		}
		return (0);	
	}
	return (0);
}
