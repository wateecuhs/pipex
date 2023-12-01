/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:48:22 by panger            #+#    #+#             */
/*   Updated: 2023/12/01 18:01:56 by panger           ###   ########.fr       */
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

# define IN 1
# define OUT 0
# define READ 0
# define WRITE 1

int		ft_putstr(char *s, int *count);
int		ft_putchar(int c, int *count);
int		ft_putnbr(int nb, int *count);
int		ft_printf(const char *str, ...);
int		ft_putadr_hexa(unsigned long adr, int *count);
int		ft_putnbr_unsigned(int n, int *count);
int		ft_putstr_hexa(int n, int caps, int *count);
int		ft_strcmp(char *s1, char *s2);
int		ft_strcmp_hd(char *s1, char *s2);

int		ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s);
int		ft_strncmp(char *s1, char *s2, int n);
char	**ft_split(char *s, char *c);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*join_paths(char *s1, char *s2);
void	freetab(char **tab);
char	*find_path(char *cmd, char **env);
void	error_msg(void);

char	**get_paths(char **env);

int		check_files(char **argv, int argc);
int		command_receiver(int nb_cmd, char **cmds, char **env, int *fd_in_and_out);
int		command_receiver_here_doc(char **argv, char **env, int argc);

char	*get_next_line(int fd);
int		ft_strlen(char *str);
int		ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_strdupset(char const *s, int start, int stop);
char	*ft_strdup(const char *s);
char	*ft_stradd(char *s1, char *s2, int size);

int		command_executer_heredoc(char *cmd, char **env, int p[2], int fd2);
int		get_fd_heredoc(char **argv, int argc, int i);
void	parent_process_1_heredoc(int p[2]);
void	parent_process_heredoc(int p[2], char **argv);



#endif