/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:49:56 by panger            #+#    #+#             */
/*   Updated: 2023/11/24 16:46:15 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
	args = ft_split(cmd1);
	path = ft_strjoin("/bin/", args[0]);
	out_fd = open(file2, O_CREAT | O_WRONLY | O_TRUNC, 0777);
	pid = fork();
	if (pid == 0)
	{
		dup2(p[1], 1);
		execve(path, args, env);
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("her2e");
		c = -1;
        close(p[1]);
		dup2(p[0], 0);
		dup2(out_fd, 1);
		args = ft_split(cmd2);
		path = ft_strjoin("/bin/", args[0]);
		execve(path, args, env);
	}
}

int	checking(char **argv)
{
	char	*infile;
	char	*outfile;
	int		out_fd;

	infile = argv[0];
	outfile = argv[3];
	if ((access(infile, R_OK)) == -1)
		return (-1);
	if ((access(outfile, F_OK)) == -1)
	{
		out_fd = open(outfile, O_CREAT | O_WRONLY | O_TRUNC, 0777);
		if ((access(outfile, W_OK)) == -1)
			return (-1);
	}
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	if (argc != 5)
		return (program_failure(1), 1);
	else
	{
		checking(&argv[1]);
		executing(argv[1], argv[4], argv[2], argv[3], env);
	}
		
}
/* 

#include <stdio.h>
#include <unistd.h>
int main ()
{ 
	char *argv[]={"cat", "infile", NULL};
  	char *env[]={"PATH=/usr/local/sbin/:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin",NULL};
  	execve("/bin/cat", argv, env);
	printf("here");
  	return 0;
 } */