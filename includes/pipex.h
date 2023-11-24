/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:48:22 by panger            #+#    #+#             */
/*   Updated: 2023/11/24 16:07:08 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>

int		program_failure(int error_type);
void	do_cmd(char *path, char **args, char *outfile,char **env);

int		ft_strlen(char *s);
char 	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s);
char	**ft_split(char const *s);

#endif