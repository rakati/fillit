/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@protonmail>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 12:26:47 by abiri             #+#    #+#             */
/*   Updated: 2018/10/21 23:38:35 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "fillit.h"

int			readfile(int ac, char **av, char *buffer)
{
	int		rd;
	int		fd;

	if (ac != 2)
	{
		ft_putstr("usage : ./fillit input_file\n");
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	rd = read(fd, buffer, BUFF_SIZE);
	if (rd < 20)
	{
		ft_putstr("error\n");
		return (0);
	}
	buffer[rd] = '\0';
	if (buffer[rd - 1] == buffer[rd - 2])
	{
		ft_putstr("error\n");
		return (0);
	}
	return (1);
}

int			main(int ac, char **av)
{
	char	buffer[BUFF_SIZE + 1];
	char	**tab;
	t_tetri	**tetritab;
	char	**board;

	if (!readfile(ac, av, buffer))
		return (0);
	if (!(dothashverify(buffer, &tab)) || !(shapeverify(tab)))
	{
		ft_putstr("error\n");
		return (0);
	}
	tetritab = fill_tetriminos(tab);
	board = create_board();
	initboard(board, optimalinitboard(tab));
	brain(board, tetritab, 1);
	print_board(board);
	return (0);
}
