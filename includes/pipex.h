/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:48:22 by panger            #+#    #+#             */
/*   Updated: 2023/11/28 15:46:51 by panger           ###   ########.fr       */
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
# include <stdarg.h>
# include <string.h>

int		ft_putstr(char *s, int *count);
int		ft_putchar(int c, int *count);
int		ft_putnbr(int nb, int *count);
int		ft_printf(const char *str, ...);
int		ft_putadr_hexa(unsigned long adr, int *count);
int		ft_putnbr_unsigned(int n, int *count);
int		ft_putstr_hexa(int n, int caps, int *count);

int		program_failure(int error_type);

int		ft_strlen(char *s);
char 	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s);
int     ft_strncmp(char *s1, char *s2, int n);
char	**ft_split(char *s, char *c);
char	*ft_substr(char *s, unsigned int start, size_t len);
char    *join_paths(char *s1, char *s2);
void    freetab(char **tab);
char	*find_path(char *cmd, char **env);

char    **get_paths(char **env);

int	    check_files(char **argv, int argc);
int 	command_receiver(char **argv, char **env, int argc);

#endif