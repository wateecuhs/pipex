/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:59:02 by panger            #+#    #+#             */
/*   Updated: 2023/11/29 11:05:56 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_putstr(char *s, int *count)
{
	int	i;

	if (!s)
	{
		if (write(2, "(null)", 6) == -1)
			return (-1);
		*count += 6;
		return (1);
	}
	i = 0;
	while (s[i])
	{
		if (write(2, &s[i], 1) == -1)
			return (-1);
		*count += 1;
		i++;
	}
	return (1);
}
