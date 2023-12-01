/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:49:56 by panger            #+#    #+#             */
/*   Updated: 2023/12/01 17:29:04 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	int	status;

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
	status = command_receiver(&argv[1], env, argc - 1);
	return (status);
}
