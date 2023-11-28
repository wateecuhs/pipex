/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:49:56 by panger            #+#    #+#             */
/*   Updated: 2023/11/28 15:49:32 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	int	status;

	if (argc != 5)
		program_failure(1);
	else
	{
		status = command_receiver(&argv[1], env, argc - 1);
		return (status);
	}
	return (0);
}
