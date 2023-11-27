/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:48:22 by panger            #+#    #+#             */
/*   Updated: 2023/11/27 18:26:16 by panger           ###   ########.fr       */
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

int		ft_strlen(char *s);
char 	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s);
int     ft_strncmp(char *s1, char *s2, int n);
char	**ft_split(char *s, char *c);
char	*ft_substr(char *s, unsigned int start, size_t len);
char    *join_paths(char *s1, char *s2);
void    freetab(char **tab);

char    **get_paths(char **env);

int	    check_files(char **argv, int argc);
int	    check_cmds(char **argv, char **env, int argc);
int 	command_receiver(char **argv, char **env, int argc);

#endif