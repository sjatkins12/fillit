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


void			check_tetrimino(t_tetrimino *t);

void			error_handle()
{
	ft_putstr("error\n");
	exit(0);
}


void			read_file(int fd, t_tetrimino *tetriminos)
{
	char		buffer[5];
	int			ret;
	int			k;
	int			i;
	t_tetrimino	*hold;

	buffer[0] = '\n';
	k = 0;
	ret = 1;
	while (ret == 1 && buffer[0] == '\n' && (i = -1))
	{
		while (++i < 4)
		{
			ret = read(fd, buffer, 5);
			if (ret != 5 || buffer[4] != '\n')
				error_handle(); //Bad tetrimino
			ft_strncpy(tetriminos->grid[i], buffer, 4);
			tetriminos->grid[i][4] = '\0';
		}
		ret = read(fd, buffer, 1);
		if (ret == 1 && buffer[0] != '\n')
			error_handle();
		tetriminos->num = 'A' + k;
		check_tetrimino(tetriminos);
		hold = tetriminos++;
		hold->next = tetriminos;
		k++;
	}
	hold->next = NULL;
}

void			edge_check(char grid[4][5], int i, int j)
{
	if (i > 0 && grid[i - 1][j] == '#')
		return ;
	if (j > 0 && grid[i][j - 1] == '#')
		return ;
	if (j < 3 && grid[i][j + 1] == '#')
		return ;
	if (i < 3 && grid[i + 1][j] == '#')
		return ;
	error_handle();
}

void			type_check(int i, int j, t_tetrimino *t)
{
	/*
	....
	....
	..##
	..##
	*/
	if (i == 2 && j == 2)
	{
		if (t->grid[i + 1][j + 1] == '#' && t->grid[i + 1][j] == '#' &&
			t->grid[i][j + 1] == '#' && (t->type = 's'))
			return ;
		else
			error_handle();
	}
	/*
	#...
	#...
	#...
	#...
	*/
	if (i == 0)
	{
		if (t->grid[i + 1][j] == '#' && t->grid[i + 2][j] == '#' && 
			t->grid[i + 3][j] == '#' && (t->type = 'i'))
			return ;
	}
	/*
	####
	....
	....
	....
	*/
	if (j == 0)
	{
		if (t->grid[i][j + 1] == '#' && t->grid[i][j + 2] == '#' && 
			t->grid[i][j + 3] == '#' && (t->type = 'i'))
			return ;
	}
	if (j == 3 || i == 3)
		error_handle();
	
	if (t->grid[i + 1][j + 1] == '#' && t->grid[i + 1][j] == '#' &&
		t->grid[i][j + 1] == '#' && (t->type = 's'))
		return ;

	/*
	.###
	.#..->
	....
	....
	*/
	if (j < 2 && t->grid[i][j + 1] == '#' && t->grid[i][j + 2] == '#' && (
			t->grid[i + 1][j] == '#' || t->grid[i + 1][j + 1] == '#' || 
			t->grid[i + 1][j + 2] == '#'))
		return ;

	/*
	.... ....
	##.. .#..
	#... ##..
	#... .#..
	*/
	if (i < 2 && t->grid[i + 1][j] == '#' && t->grid[i + 2][j] == '#' && ((
			t->grid[i][j + 1] == '#' || t->grid[i + 1][j + 1] == '#' || 
			t->grid[i + 2][j + 1] == '#') || (j > 0 && (
			t->grid[i + 1][j - 1] == '#' || 
			t->grid[i + 2][j - 1] == '#'))))
		return ;

	/*
	.##. .##.
	..## ##..
	.... ....
	.... ....
	*/
	if (t->grid[i][j + 1] == '#' && ((j < 2 && t->grid[i + 1][j + 1] == '#' && 
		t->grid[i + 1][j + 2] == '#') || (j > 0 && t->grid[i + 1][j] == '#' &&
		t->grid[i + 1][j - 1] == '#')))
		return ;

	/*
	.... .#..
	#... ##..
	##.. #...
	.#.. ....
	*/
	if (i < 2 && t->grid[i + 1][j] == '#' && ((t->grid[i + 1][j + 1] == '#' && 
		t->grid[i + 2][j + 1] == '#') || (j > 0 && t->grid[i + 1][j - 1] == '#'
		&& t->grid[i + 2][j - 1] == '#')))
		return ;

	/*
	..##
	...#
	...#
	....
	*/

	if (i < 2 && t->grid[i][j + 1] == '#' && t->grid[i + 1][j + 1] == '#' 
		&& t->grid[i + 2][j + 1] == '#')
		return ;

	/*
	#... .#.. ..#.
	###. ###. ###.
	.... .... ....
	.... .... ....
	*/
	if (t->grid[i + 1][j] == '#' && ((j < 2 && t->grid[i + 1][j + 1] == '#'
		&& t->grid[i + 1][j + 2] == '#') || (j > 0 && 
		t->grid[i + 1][j - 1] == '#' && t->grid[i + 1][j + 1] == '#') || (j > 1
		&& t->grid[i + 1][j - 1] == '#' && t->grid[i + 1][j - 2] == '#')))
		return ;
	error_handle();	
}

void			check_tetrimino(t_tetrimino *t)
// This is to check to see if valid tetrimino. Also this must set the dimensions of the tetrimino and type if applicable. Size is confirmed. 4x4 with terminating characters
{
	int			i;
	int			j;
	int			p_count;
	int			ip;
	int			jp;

	i = -1;
	p_count = 0;
	t->xdim = 0;
	t->ydim = 0;
	while (++i < 4 && (j = -1))
	{
		while (++j < 4)
		{
			if (t->grid[i][j])
			{
				if (t->grid[i][j] != '#' && t->grid[i][j] != '.')
					error_handle();
				if (t->grid[i][j] == '#')
				{
					edge_check(t->grid, i, j);
					if (p_count == 0)
					{
						type_check(i, j, t);
						jp = j;
						ip = i;
					}
					if (i - ip + 1 > t->ydim)
						t->ydim = i - ip + 1;
					if (j - jp + 1 > t->xdim)
						t->xdim = j - jp + 1;
					p_count++;
				}
			}
		}
	}
	if (p_count != 4)
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
		error_handle(); //Give usage
	tetriminos = (t_tetrimino *)malloc(sizeof(t_tetrimino) * 26);
	read_file(fd, tetriminos);
	ft_place_tetriminos(tetriminos);
	free(tetriminos);
}
