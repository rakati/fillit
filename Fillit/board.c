/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouhaddo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 19:26:04 by nouhaddo          #+#    #+#             */
/*   Updated: 2018/10/21 17:15:08 by nouhaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**create_board(void)
{
	char	**board;
	int		i;

	if (!(board = (char**)malloc(53 * sizeof(char*))))
		return (0);
	i = 0;
	while (i < 52)
	{
		if (!(board[i] = (char*)malloc(53 * sizeof(char))))
			return (0);
		board[i] = ft_memset((void*)board[i], '0', 52);
		board[i++][52] = '\0';
	}
	board[52] = NULL;
	return (board);
}

void		print_board(char **board)
{
	int		i;
	int		j;

	i = 0;
	while (board[i][0] != '0')
	{
		j = 0;
		while (board[i][j] != '0')
		{
			ft_putchar(board[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int			optimalinitboard(char **tab)
{
	int i;
	int res;

	i = 0;
	while (tab[i])
		i++;
	i *= 4;
	res = 1;
	while (res * res < i)
		res++;
	return (res);
}

void		initboard(char **board, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
			board[i][j++] = '.';
		i++;
	}
}
