/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouhaddo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 20:46:31 by nouhaddo          #+#    #+#             */
/*   Updated: 2018/10/21 21:37:20 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include "libft/libft.h"
# define BUFF_SIZE 2000

typedef struct	s_block
{
	int x;
	int y;
}				t_block;

typedef struct	s_tetri
{
	char		letter;
	t_block		block[4];
}				t_tetri;

int				shapeverify(char **tab);
int				dothashverify(char *str, char ***tab);
t_tetri			**fill_tetriminos(char **tab);
int				get_xy(int k, int i, char xy);
char			**create_board(void);
void			print_board(char **board);
void			initboard(char **board, int size);
int				place(int x, int y, t_tetri *tet, char **grid);
int				brain(char **grid, t_tetri **tet, int size);
void			unplace(int x, int y, t_tetri *tet, char **grid);
int				optimalinitboard(char **tab);

#endif
