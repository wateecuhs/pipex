/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:26:10 by panger            #+#    #+#             */
/*   Updated: 2023/11/24 13:26:20 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strdup(const char *s)
{
	int		srclen;
	int		i;
	char	*dest;

	srclen = 0;
	while (s[srclen])
		srclen++;
	i = 0;
	dest = (char *)malloc((srclen + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (i < srclen)
	{
		dest[i] = s[i];
		i ++;
	}
	dest[i] = '\0';
	return (dest);
}