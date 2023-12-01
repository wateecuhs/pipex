/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:36:57 by panger            #+#    #+#             */
/*   Updated: 2023/11/29 16:52:16 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	here_doc_init(char **env, char **argv, int argc)
{
	pid_t	pid;
	pid_t	pid2;
	int		p[2];
	int		status;

	if (pipe(p) == -1)
		error_msg();
	pid = fork();
	if (pid == -1)
		error_msg();
	if (pid == 0)
	{
		pid2 = fork();
		if (pid2 == 0)
			parent_process_heredoc(p, argv);
		waitpid(pid2, &status, 0);
		command_executer_heredoc(argv[2], env, p,
			get_fd_heredoc(argv, argc, 2));
	}
	close(p[0]);
	close(p[1]);
	waitpid(pid, &status, 0);
	return (status);
}

int	normal_cmds(char **argv, char **env, int argc, int i)
{
	pid_t	pid;
	int		p[2];
	int		status;

	if (pipe(p) == -1)
		error_msg();
	pid = fork();
	status = -1;
	if (pid == -1)
		error_msg();
	if (pid == 0)
	{
		command_executer_heredoc(argv[i], env, p,
			get_fd_heredoc(argv, argc, i));
	}
	else
	{
		parent_process_1_heredoc(p);
		waitpid(pid, &status, 0);
	}
	return (status);
}

int	command_receiver_here_doc(char **argv, char **env, int argc)
{
	int		i;
	int		status;

	i = 2;
	while (i < argc - 1)
	{
		if (i == 2)
			status = here_doc_init(env, argv, argc);
		else
			status = normal_cmds(argv, env, argc, i);
		i++;
	}
	return (status);
}
