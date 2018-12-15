/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@protonmail>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 16:49:43 by abiri             #+#    #+#             */
/*   Updated: 2018/10/21 23:45:46 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*separate_shapes(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		while ((str[i] != '\n' || str[i + 1] != '\n') && str[i + 1] != '\0')
			i++;
		str[i + 1] = '\t';
		i += 2;
	}
	return (str);
}

void		crawl(char *line, int i)
{
	line[i] = '@';
	if (line[i + 1] == '#')
		crawl(line, i + 1);
	if (line[i - 1] == '#')
		crawl(line, i - 1);
	if (line[i + 5] == '#')
		crawl(line, i + 5);
	if (line[i - 5] == '#')
		crawl(line, i - 5);
}

int			shapeverify(char **tab)
{
	int		i;
	char	**lines;

	lines = tab;
	while (*lines)
	{
		i = 0;
		while ((*lines)[i] != '#')
			i++;
		crawl(*lines, i);
		i = 0;
		while ((*lines)[i])
		{
			if ((*lines)[i] == '#')
				return (0);
			i++;
		}
		i = -1;
		ft_charreplace(*lines, '@', '#');
		lines++;
	}
	return (1);
}

int			dothashcount(char *lines, int *count, int *i)
{
	count[2] = 0;
	while (lines[*i] != '\n')
	{
		if (lines[*i] == '#')
			count[0]++;
		else if (lines[*i] == '.')
			count[1]++;
		else
			return (0);
		count[2]++;
		(*i)++;
	}
	return (1);
}

int			dothashverify(char *str, char ***tab)
{
	int		i;
	int		count[4];
	char	**lines;

	*tab = ft_strsplit(separate_shapes(str), '\t');
	lines = *tab;
	count[3] = 0;
	while (*lines && !(i = 0))
	{
		count[1] = 0;
		count[0] = 0;
		while ((*lines)[i])
		{
			if (dothashcount(*lines, count, &i) == 0)
				return (0);
			if (count[2] != 4)
				return (0);
			i = ((*lines)[i] != '\0') ? (i + 1) : i;
		}
		if (count[0] != 4 || count[1] != 12)
			return (0);
		lines++;
		count[3]++;
	}
	return ((count[3] <= 26) ? 1 : 0);
}
