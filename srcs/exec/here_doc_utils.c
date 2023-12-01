/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:22:44 by panger            #+#    #+#             */
/*   Updated: 2023/12/01 14:11:53 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_msg(void)
{
	perror("pipex");
	exit(EXIT_FAILURE);
}

int	command_executer_heredoc(char *cmd, char **env, int p[2], int fd2)
{
	char	**args;
	int		stdout_fd;

	close(p[1]);
	stdout_fd = dup(1);
	if (dup2(p[0], STDIN_FILENO))
		perror("pipex");
	close(p[0]);
	if (dup2(fd2, STDOUT_FILENO) == -1)
		error_msg();
	args = ft_split(cmd, " \t\v\n\f\r");
	cmd = find_path(cmd, env);
	if (!args || !cmd)
		error_msg();
	if (execve(cmd, args, env) == -1)
		error_msg();
	if (dup2(stdout_fd, 1) == -1)
		error_msg();
	if (errno == EFAULT)
		ft_printf("pipex: command not found: %s\n", cmd);
	else
		ft_printf("pipex: failed to execute command: %s\n", cmd);
	exit(EXIT_FAILURE);
}

int	get_fd_heredoc(char **argv, int argc, int i)
{
	int		fd2;

	if (i == argc - 2)
		fd2 = open(argv[argc - 1], O_CREAT | O_RDWR | O_APPEND, 0777);
	else
		fd2 = open("./.build/tmp", O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (fd2 == -1)
		ft_printf("pipex: %s: %s\n", strerror(errno), argv[argc - 1]);
	return (fd2);
}

void	parent_process_1_heredoc(int p[2])
{
	int		char_read;
	char	buff[2048];
	char	*path;
	int		fd;

	path = "./.build/tmp";
	fd = open(path, O_RDONLY, 0777);
	if (fd == -1)
		ft_printf("pipex: %s: %s\n", strerror(errno), path);
	close(p[0]);
	char_read = read(fd, buff, 2048);
	while (char_read > 0)
	{
		write(p[1], buff, char_read);
		char_read = read(fd, buff, 2048);
	}
	close(p[1]);
	close(fd);
}

void	parent_process_heredoc(int p[2], char **argv)
{
	char	*string;

	close(p[0]);
	string = get_next_line(0);
	while (ft_strcmp_hd(string, argv[1]) != 0 && string != NULL)
	{
		write(p[1], string, ft_strlen(string));
		string = get_next_line(0);
	}
	close(p[1]);
	exit(EXIT_SUCCESS);
}
