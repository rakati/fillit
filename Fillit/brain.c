/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@protonmail>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 16:20:16 by abiri             #+#    #+#             */
/*   Updated: 2018/10/21 15:53:36 by nouhaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		neural(int i, int size, char **grid, t_tetri **tet)
{
	int j;
	int result;

	j = 0;
	while (grid[i][j] != '\0' && grid[i][j] != '0')
	{
		result = place(j, i, *tet, grid);
		if (result)
		{
			if (*(tet + 1))
			{
				if (brain(grid, (tet + 1), size))
					return (1);
				else
					unplace(j, i, *tet, grid);
			}
			else
				return (1);
		}
		j++;
	}
	return (0);
}

int		brain(char **grid, t_tetri **tet, int size)
{
	int i;

	i = 0;
	while (grid[i])
	{
		if (neural(i, size, grid, tet))
			return (1);
		if (grid[i][0] != '0')
			i++;
		else
			break ;
	}
	if ((*tet)->letter == 'A')
	{
		initboard(grid, size + 1);
		return (brain(grid, tet, size + 1));
	}
	return (0);
}
