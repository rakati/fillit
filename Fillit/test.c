/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@protonmail>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 16:32:05 by abiri             #+#    #+#             */
/*   Updated: 2018/10/21 21:39:32 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		place(int x, int y, t_tetri *tet, char **grid)
{
	int		blk;
	t_block *square;

	blk = 1;
	if (grid[y][x] != '.')
		return (0);
	while (blk < 4)
	{
		square = &(tet->block[blk]);
		if ((square->x) + x < 0 || grid[0][(square->x) + x] == '0')
			return (0);
		if (y + (square->y) < 0 || grid[y + (square->y)][0] == '0')
			return (0);
		if (grid[y + (square->y)][x + (square->x)] != '.')
			return (0);
		blk++;
	}
	blk = 0;
	while (blk < 4)
	{
		square = &(tet->block[blk]);
		grid[y + square->y][x + square->x] = tet->letter;
		blk++;
	}
	return (1);
}

void	unplace(int x, int y, t_tetri *tet, char **grid)
{
	int		blk;
	t_block *square;

	blk = 0;
	while (blk < 4)
	{
		square = &(tet->block[blk]);
		grid[y + square->y][x + square->x] = '.';
		blk++;
	}
}
