/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params_checking.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:45:53 by panger            #+#    #+#             */
/*   Updated: 2023/11/27 17:46:14 by panger           ###   ########.fr       */
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

int	check_cmds(char **argv, char **env, int argc)
{
	int		i;
	int		j;
	char	**paths;
	char	*temp;
	int		found;

	i = 1;
	found = 0;
	paths = get_paths(env);
	while (i < argc - 1)
	{
		j = 0;
		while (paths[j] && found == 0)
		{
			temp = join_paths(paths[j++], argv[i]);
			if (access(temp, F_OK) != -1)
				found = 1;
			free(temp);
		}
		if (found == 0)
			return (freetab(paths), -1);
		i++;
	}
	freetab(paths);
	return (0);
}
