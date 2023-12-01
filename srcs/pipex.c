/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:49:56 by panger            #+#    #+#             */
/*   Updated: 2023/12/01 18:20:49 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	*set_fd(int *fd_in_out, char *infile, char *outfile)
{
	fd_in_out[IN] = open(infile, O_RDONLY);
	if (fd_in_out[IN] == -1)
		perror(infile);
	fd_in_out[OUT] = open(outfile, O_CREAT | O_WRONLY | O_WRONLY, 0777);
	if (fd_in_out[OUT] == -1)
		perror(outfile);
	printf("fd = %d\n", fd_in_out[OUT]);
	return (fd_in_out);
}

int	main(int argc, char **argv, char **env)
{
	int	status;
	int	fd_in_out[2];

	if (argc < 5)
	{
		ft_printf("pipex: invalid number of arguments.\n");
		exit(EXIT_FAILURE);
	}	
	if (ft_strcmp(argv[1], "here_doc") == 0)
	{
		if (argc < 6)
		{
			ft_printf("pipex: invalid number of arguments.\n");
			exit(EXIT_FAILURE);
		}
		status = command_receiver_here_doc(&argv[1], env, argc - 1);
		return (status);
	}
	set_fd(fd_in_out, argv[1], argv[argc - 1]);
	status = command_receiver( argc - 3, &argv[2], env, fd_in_out);
	return (status);
}
