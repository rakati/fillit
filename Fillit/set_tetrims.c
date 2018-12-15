/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetgen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@protonmail>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 15:19:40 by abiri             #+#    #+#             */
/*   Updated: 2018/10/21 20:08:21 by nouhaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			find_char(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i++] == c)
			return (i - 1);
	}
	return (-1);
}

void		initiallize_block(t_tetri **tetriminos, char **input)
{
	char	ltr;
	int		j;

	ltr = 'A';
	j = 0;
	while (*input)
	{
		tetriminos[j]->block[0].x = 0;
		tetriminos[j]->block[0].y = 0;
		tetriminos[j]->letter = ltr++;
		j++;
		input++;
	}
}

int			get_xy(int k, int i, char xy)
{
	if (xy == 'x')
	{
		while (i / 5 > k / 5)
			k += 5;
		return (i - k);
	}
	else if (xy == 'y')
		return (i / 5 - k / 5);
	return (0);
}

void		set_positions(t_tetri **tetriminos, char **input)
{
	int		i;
	int		j;
	int		k;
	int		block;

	j = 0;
	while (*input)
	{
		block = 1;
		i = find_char(*input, '#');
		k = i++;
		while ((*input)[i] != '\0')
		{
			if ((*input)[i] == '#')
			{
				tetriminos[j]->block[block].y = get_xy(k + 1, i + 1, 'y');
				tetriminos[j]->block[block].x = get_xy(k + 1, i + 1, 'x');
				block++;
			}
			i++;
		}
		j++;
		input++;
	}
}

t_tetri		**fill_tetriminos(char **tab)
{
	char		**input;
	t_tetri		**tetriminos;
	int			i;

	input = tab;
	i = 0;
	while (input[i])
		i++;
	tetriminos = (t_tetri**)malloc(sizeof(t_tetri*) * (i + 1));
	tetriminos[i] = NULL;
	while (--i >= 0)
		tetriminos[i] = (t_tetri*)malloc(sizeof(t_tetri));
	initiallize_block(tetriminos, input);
	set_positions(tetriminos, input);
	return (tetriminos);
}
