/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:49:56 by panger            #+#    #+#             */
/*   Updated: 2023/11/27 18:26:56 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
/* 
void executing(char *file1, char *file2, char *cmd1, char *cmd2, char **env)
{
	pid_t	pid;
	char	*path;
	int		out_fd;
	char	**args;
	int		c;
    int 	p[2];

	pipe(p);
	cmd1 = ft_strjoin(cmd1, " ");
	cmd1 = ft_strjoin(cmd1, file1);
	args = ft_split(cmd1, " \t\v\n\f\r");
	path = ft_strjoin("/bin/", args[0]);
	out_fd = open(file2, O_CREAT | O_WRONLY | O_TRUNC, 0777);
	pid = fork();
	(void)env;
	if (pid == 0)
	{
		dup2(p[1], 1);
		//execve(path, args, env);
	}
	else
	{
		c = -1;
        close(p[1]);
		dup2(p[0], 0);
		dup2(out_fd, 1);
		args = ft_split(cmd2, " \t\v\n\f\r");
		path = ft_strjoin("/bin/", args[0]);
		//execve(path, args, env);
	}
} */

int	main(int argc, char **argv, char **env)
{
	if (argc != 5)
		program_failure(1);
	else
	{
		if (check_files(&argv[1], argc - 1) == -1)
			program_failure(2);
		if (check_cmds(&argv[1], env, argc - 1) == -1)
			program_failure(3);
		command_receiver(&argv[1], env, argc - 1);
	}
	return (0);
}
