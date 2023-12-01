/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:13:39 by panger            #+#    #+#             */
/*   Updated: 2023/12/01 14:01:12 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"



char	*ft_substr(char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			src_len;
	char			*ret;

	src_len = 0;
	while (s[src_len])
		src_len++;
	if (start > src_len)
	{
		len = 0;
		start = 0;
	}
	if (src_len - start < len)
		len = src_len - start;
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		ret[i] = s[start + i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
