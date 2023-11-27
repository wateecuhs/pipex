/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:17:11 by panger            #+#    #+#             */
/*   Updated: 2023/11/27 17:42:47 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	program_failure(int error_type)
{
	if (error_type == 1)
		write(2, "Invalid parameters.\n", 21);
	if (error_type == 2)
		write(2, "Couldn't access the given files.\n", 34);
	if (error_type == 3)
		write(2, "Command not found.\n", 20); 
	exit(EXIT_FAILURE);
}