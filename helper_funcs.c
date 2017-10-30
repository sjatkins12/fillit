/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satkins <satkins@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 16:05:55 by satkins           #+#    #+#             */
/*   Updated: 2017/10/30 16:05:58 by satkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void			read_file_helper(int a[3], char buffer[5])
{
	buffer[0] = '\n';
	a[2] = 0;
	a[1] = 1;
}

void			type_check_helper(int i, int j, t_tetrimino *t)
{
	if (i < 2 && t->grid[i + 1][j] == '#' && t->grid[i + 2][j] == '#' &&
		((j < 3 && (t->grid[i][j + 1] == '#' || t->grid[i + 1][j + 1] == '#' ||
		t->grid[i + 2][j + 1] == '#')) || (j > 0 && (
		t->grid[i + 1][j - 1] == '#' ||
		t->grid[i + 2][j - 1] == '#'))))
		return ;
	if (j < 3 && i < 3 &&
		t->grid[i][j + 1] == '#' && ((j < 2 && t->grid[i + 1][j + 1] == '#' &&
		t->grid[i + 1][j + 2] == '#') || (j > 0 && t->grid[i + 1][j] == '#' &&
		t->grid[i + 1][j - 1] == '#')))
		return ;
	if (i < 2 && t->grid[i + 1][j] == '#' && ((j < 3 && t->grid[i + 1][j + 1]
		== '#' && t->grid[i + 2][j + 1] == '#') || (j > 0
		&& t->grid[i + 1][j - 1] == '#' && t->grid[i + 2][j - 1] == '#')))
		return ;
	if (j < 3 && i < 3 &&
		i < 2 && t->grid[i][j + 1] == '#' && t->grid[i + 1][j + 1] == '#'
		&& t->grid[i + 2][j + 1] == '#')
		return ;
	if (t->grid[i + 1][j] == '#' && ((j < 2 && t->grid[i + 1][j + 1] == '#'
		&& t->grid[i + 1][j + 2] == '#') || (j > 0 &&
		t->grid[i + 1][j - 1] == '#' && t->grid[i + 1][j + 1] == '#') || (j > 1
		&& t->grid[i + 1][j - 1] == '#' && t->grid[i + 1][j - 2] == '#')))
		return ;
	error_handle();
}

void			type_check(int i, int j, t_tetrimino *t)
{
	if (i == 0)
	{
		if (t->grid[i + 1][j] == '#' && t->grid[i + 2][j] == '#' &&
			t->grid[i + 3][j] == '#' && (t->type = 'i'))
			return ;
	}
	if (j == 0)
	{
		if (t->grid[i][j + 1] == '#' && t->grid[i][j + 2] == '#' &&
			t->grid[i][j + 3] == '#' && (t->type = 'i'))
			return ;
	}
	if (j < 3 && i < 3 &&
		t->grid[i + 1][j + 1] == '#' && t->grid[i + 1][j] == '#' &&
		t->grid[i][j + 1] == '#' && (t->type = 's'))
		return ;
	if (j < 2 && t->grid[i][j + 1] == '#' && t->grid[i][j + 2] == '#' && (
			t->grid[i + 1][j] == '#' || t->grid[i + 1][j + 1] == '#' ||
			t->grid[i + 1][j + 2] == '#'))
		return ;
	type_check_helper(i, j, t);
}

void			helper(int a[5], t_tetrimino *t)
{
	type_check(a[0], a[2], t);
	a[4] = a[2];
	a[3] = a[0];
}

void			error_handle(void)
{
	ft_putstr("error\n");
	exit(0);
}
