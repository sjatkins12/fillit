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
	if ((size_t)x + t.xdim > len || (size_t)y + t.ydim > len)
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
					return (0);


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
	//Entry into placement logic
	//Input: Linked List of Tetriminos, current Answer Grid, dimensions of grid, finished Flag. 
	int		i; //Y
	int		j; //X

	i = -1;
	if (room_check(*tetrimino, grid, dimensions)) //Evaluates answer grid for room.
		return (grid); // This is a failure to place the tetrimino
	while (++i < dimensions) //Iterate Y direction
	{
		j = -1;
		while (++j < dimensions) //Iterate X direction
		{
			if (grid[i][j] == '.' && sp_check(grid, i, j, *tetrimino) == 1) //evaluates the tetrimino and the answer grid. This determines if it can fit at this index.
			{

				// This block executes only if the tetrimino can fit
				if (tetrimino->next) //Is this not the last tetrimino in the list
					ft_placeable(tetrimino->next, grid, dimensions, placeable); //Recursively call this funciton with the next tetrimino in the linked list
				else
					*placeable = 1; // No tetriminos left in the linked list. And the current Tetrimino has room. We have filled the answer grid. Set the flag to 1
				if (*placeable == 1) // Exit on success
					return (grid); // Filled answer grid
			}
			else

			restore_grid(grid, *tetrimino, j, i); //Answer grid could not be filled with the tetrimno at this index. Remove all characters of the current tetrimino from the answer grid. This does not nessasarly mean the tetrimino couldnt fit, it could also mean a tetrimino later in the linked list couldnt fit.
		}
	}
	return (grid); //Failure to place tetrimino into the answer grid. Return to either ft_place_tetriminos to increase answer grid dimensions, or to the tetrimino prior to this tetrimino in the linked list.
}
