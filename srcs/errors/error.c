/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:17:11 by panger            #+#    #+#             */
/*   Updated: 2023/11/24 12:18:33 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	program_failure(int error_type)
{
	if (error_type == 1)
		write(2, "Wrong params\n", 14);

	exit(EXIT_FAILURE);
}