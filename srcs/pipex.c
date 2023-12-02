/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:49:56 by panger            #+#    #+#             */
/*   Updated: 2023/12/02 13:10:46 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
		set_fd_heredoc(fd_in_out, argv[2], argv[argc - 1]);
		status = command_receiver(argc - 4, &argv[3], env, fd_in_out);
		return (status);
	}
	set_fd(fd_in_out, argv[1], argv[argc - 1]);
	status = command_receiver(argc - 3, &argv[2], env, fd_in_out);
	status = WEXITSTATUS(status);
	return (status);
}
