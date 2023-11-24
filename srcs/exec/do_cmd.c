/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:56:29 by panger            #+#    #+#             */
/*   Updated: 2023/11/24 16:22:48 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	do_cmd(char *path, char **args, char *outfile,char **env)
{
	int			out_fd;
	pid_t		pid;

	pid = fork();
	if (pid == 0)
	{
		printf("path %s\n", path);
		int	i = 0;
		while (args[i])
		{
			printf("ok : %s \n", args[i++]);
			fflush(stdout);
		}
		out_fd = open(outfile, O_CREAT | O_WRONLY | O_TRUNC, 0777);
		dup2(out_fd, 1);
		execve(path, args, env);
	}
}
