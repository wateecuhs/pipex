/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:19:29 by panger            #+#    #+#             */
/*   Updated: 2023/11/27 17:40:22 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char    *join_paths(char *s1, char *s2)
{
    char    *ret;
    char    *temp;
    char    *temp2;
    int     i;

    temp2 = ft_strjoin(s1, "/");
    temp = s2;
    i = 0;
    while (temp[i] && temp[i] != ' ')
        i++;
    if (temp[i])
        temp[i] = '\0';
    ret = ft_strjoin(temp2, temp);
    free(temp2);
    return (ret);
}