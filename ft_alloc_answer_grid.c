/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_answer_grid.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satkins <satkins@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 20:19:49 by satkins           #+#    #+#             */
/*   Updated: 2017/10/06 20:19:54 by satkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			x_check(int consectutive, char **grid, int dimensions)
{
	int		i;
	int		j;
	int		dot_count;
	int		con;
	int		con_max;

	i = -1;
	dot_count = 0;
	while (++i < dimensions && (j = -1) && (con = 0))
	{
		while (++j < dimensions)
		{
			if (grid[i][j] == '.' && (con++) && (dot_count++))
			{
				if (con > con_max)
					con_max = con;
			}
			else
				con = 0;
		}
	}
	if (dot_count < 4 || con_max < consectutive)
		return (0);
	return (1);
}

int			y_check(int consectutive, char **grid, int dimensions)
{
	int		i;
	int		j;
	int		dot_count;
	int		con;
	int		con_max;

	i = -1;
	dot_count = 0;
	while (++i < dimensions && (j = -1) && (con = 0))
	{
		while (++j < dimensions)
		{
			if (grid[j][i] == '.' && (con++) && (dot_count++))
			{
				if (con > con_max)
					con_max = con;
			}
			else
				con = 0;
		}
	}
	if (dot_count < 4 || con_max < consectutive)
		return (0);
	return (1);
}

int			room_check(t_tetrimino t, char **grid, int dimensions)
{

	if (t.xdim >= t.ydim)
		return (x_check(t.xdim, grid, dimensions));
	else
		return (y_check(t.ydim, grid, dimensions));
}

char		**ft_alloc_answer_grid(int dimensions, char **old_grid)
{
	int		i;
	char	**new_grid;
	while (old_grid != NULL && *old_grid)
	{
		free(*old_grid);
		*old_grid = NULL;
		old_grid++;
	}
	old_grid = NULL;
	new_grid = (char **)malloc(sizeof(char *) * (dimensions + 1));
	if (!new_grid)
		return (NULL);
	i = -1;
	while (++i < dimensions)
	{
		new_grid[i] = (char *)malloc(sizeof(char) * (dimensions + 1));
		if (!new_grid[i])
			return (NULL);
		ft_memset(new_grid[i], '.', dimensions);
		new_grid[i][dimensions] = '\0';
	}
	new_grid[i] = NULL;
	return (new_grid);
}
