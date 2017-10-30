/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satkins <satkins@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 16:25:40 by satkins           #+#    #+#             */
/*   Updated: 2017/10/16 16:25:44 by satkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void			read_file(int fd, t_tetrimino *tetriminos)
{
	char		buffer[5];
	int			a[3];
	t_tetrimino	*hold;

	read_file_helper(a, buffer);
	while (a[1] == 1 && buffer[0] == '\n' && (a[0] = -1))
	{
		while (++a[0] < 4)
		{
			a[1] = read(fd, buffer, 5);
			if (a[1] != 5 || buffer[4] != '\n')
				error_handle();
			ft_strncpy(tetriminos->grid[a[0]], buffer, 4);
			tetriminos->grid[a[0]][4] = '\0';
		}
		a[1] = read(fd, buffer, 1);
		if (a[1] == 1 && buffer[0] != '\n')
			error_handle();
		tetriminos->num = 'A' + a[2];
		check_tetrimino(tetriminos);
		hold = tetriminos++;
		hold->next = tetriminos;
		a[2]++;
	}
	hold->next = NULL;
}

int				edg_chk(char grid[4][5], int i, int j)
{
	if (i > 0 && grid[i - 1][j] == '#')
		return (1);
	if (j > 0 && grid[i][j - 1] == '#')
		return (1);
	if (j < 3 && grid[i][j + 1] == '#')
		return (1);
	if (i < 3 && grid[i + 1][j] == '#')
		return (1);
	error_handle();
	return (0);
}

void			check_tetrimino(t_tetrimino *t)
{
	int			a[5];

	a[0] = -1;
	a[1] = 0;
	t->xdim = 0;
	t->ydim = 0;
	while (++a[0] < 4 && (a[2] = -1))
		while (++a[2] < 4)
			if (t->grid[a[0]][a[2]])
			{
				if (t->grid[a[0]][a[2]] != '#' && t->grid[a[0]][a[2]] != '.')
					error_handle();
				if (t->grid[a[0]][a[2]] == '#' && edg_chk(t->grid, a[0], a[2]))
				{
					if (a[1] == 0)
						helper(a, t);
					if (a[0] - a[3] + 1 > t->ydim)
						t->ydim = a[0] - a[3] + 1;
					if (a[2] - a[4] + 1 > t->xdim)
						t->xdim = a[2] - a[4] + 1;
					a[1]++;
				}
			}
	if (a[1] != 4)
		error_handle();
}

int				main(int argc, char **argv)
{
	int			fd;
	t_tetrimino	*tetriminos;

	if (argc != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		exit(0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error_handle();
	tetriminos = (t_tetrimino *)malloc(sizeof(t_tetrimino) * 26);
	read_file(fd, tetriminos);
	ft_place_tetriminos(tetriminos);
	free(tetriminos);
}
