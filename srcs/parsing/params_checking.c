/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params_checking.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:45:53 by panger            #+#    #+#             */
/*   Updated: 2023/11/28 16:36:55 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_files(char **argv, int argc)
{
	char	*infile;
	char	*outfile;
	int		out_fd;

	infile = argv[0];
	outfile = argv[argc - 1];
	if ((access(infile, F_OK)) == -1)
		return (-1);
	if ((access(infile, R_OK)) == -1)
		return (-1);
	if ((access(outfile, F_OK)) == -1)
	{
		out_fd = open(outfile, O_CREAT | O_WRONLY | O_TRUNC, 0777);
		if ((access(outfile, W_OK)) == -1)
			return (-1);
	}
	return (0);
}

char	*find_path(char *cmd, char **env)
{
	int		j;
	char	**paths;
	char	*temp;
	int		found;

	found = 0;
	j = 0;
	if (access(cmd, F_OK) != -1)
	{
		return (cmd);
	}
	paths = get_paths(env);
	while (paths[j] && found == 0)
	{
		temp = join_paths(paths[j++], cmd);
		if (access(temp, F_OK) != -1 && access(temp, X_OK) != -1)
			found = 1;
		else
			free(temp);
	}
	if (found == 1)
		return (freetab(paths), temp);
	freetab(paths);
	return (NULL);
}