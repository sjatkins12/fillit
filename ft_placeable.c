/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placeable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satkins <satkins@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 20:20:14 by satkins           #+#    #+#             */
/*   Updated: 2017/10/06 20:20:18 by satkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		set_start_num(size_t *starti, size_t *startj, size_t i, size_t j)
{
	*startj = j;
	*starti = i;
}

int			sp_check(char **grid, int y, int x, t_tetrimino t)
{
	size_t		i;
	size_t		j;
	size_t		ip;
	size_t		jp;
	size_t		len;

	i = -1;
	set_start_num(&ip, &jp, (size_t)5, (size_t)5);
	len = ft_strlen(grid[0]);
	if ((size_t)x + t.xdim >= len + 1 || (size_t)y + t.ydim >= len + 1)
		return (0);
	while (++i < 4 && (j = -1))
	{
		while (++j < 4)
		{
			if (t.grid[i][j] == '#')
			{
				if (ip == 5 && jp == 5)
					set_start_num(&ip, &jp, i, j);
				if (grid[y - ip + i][x + j - jp] != '.')
					return 0;
				grid[y + i - ip][x + j - jp] = t.num;
			}
		}
	}
	return (1);
}

void		restore_grid(char **grid, t_tetrimino t, int x, int y)
{
	int		i;
	int		j;
	size_t	len;

	i = -1;
	len = ft_strlen(grid[0]);
	while (++i < t.ydim)
	{
		j = -1;
		while (++j < t.xdim)
		{
			if (((size_t)x + j < len && (size_t)y + i < len) 
				&& grid[y + i][x + j] == t.num)
				grid[y + i][x + j] = '.';
		}
	}
}

char		**ft_placeable(t_tetrimino *tetrimino, 
	char **grid, int dimensions, int *placeable)
{
	int		i;
	int		j;

	i = -1;
	if (room_check(*tetrimino, grid, dimensions))
		return (grid);
	while (++i < dimensions)
	{
		j = -1;
		while (++j < dimensions)
		{
			if (grid[i][j] == '.' && sp_check(grid, i, j, *tetrimino) == 1)
			{
				if (tetrimino->next)
					ft_placeable(tetrimino->next, grid, dimensions, placeable);
				else
					*placeable = 1;
				if (*placeable == 1)
					return (grid);
			}
			restore_grid(grid, *tetrimino, j, i);
		}
	}
	return (grid);
}
