/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:26:33 by panger            #+#    #+#             */
/*   Updated: 2023/11/24 13:31:28 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	is_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (0);
	return (1);
}

static char	*ft_strdupset(char const *s, int start, int stop)
{
	char			*trg;
	unsigned int	count;
	int				i;

	i = 0;
	count = 0;
	while (s[count])
		count++;
	trg = (char *)malloc((stop - start + 1) * sizeof(char));
	if (!trg)
		return (NULL);
	while (s[start] && start < stop)
	{
		trg[i] = s[start];
		i++;
		start++;
	}
	trg[i] = '\0';
	return (trg);
}

static unsigned int	next_charset(char const *s, int i)
{
	int	k;

	k = i;
	while (s[k])
	{
		if (is_space(s[k]) == 0)
			return (k);
		k++;
	}
	return (k);
}

static unsigned int	count_words(char const *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if ((is_space(s[i + 1] == 0) || s[i + 1] == '\0') && (is_space(s[i + 1]) == 1))
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s)
{
	char			**tab;
	unsigned int	i;
	unsigned int	k;
	unsigned int	count;

	i = 0;
	k = 0;
	if (!s)
		return (NULL);
	count = count_words(s);
	tab = (char **)malloc((count + 1) * sizeof(char *));
	if (tab == NULL)
		return (NULL);
	while (s[i])
	{
		if (is_space(s[i]) == 1)
		{
			tab[k++] = ft_strdupset(s, i, next_charset(s, i));
			i = next_charset(s, i);
		}
		if (s[i])
			i++;
	}
	tab[k] = 0;
	return (tab);
}