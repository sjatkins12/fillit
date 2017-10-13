/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_tetriminos.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satkins <satkins@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 20:19:12 by satkins           #+#    #+#             */
/*   Updated: 2017/10/06 20:19:15 by satkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_place_tetriminos(t_tetrimino *tetriminos)
{
	//Entry into placement Logic.
	//Input: Linked List of Tetriminos
	//Output: Will end with a printed answer grid to STDOUT
	int		dimensions;
	char	**answer_grid;
	int		flag;

	if (tetriminos->type && tetriminos->type == 's')
		dimensions = 2;
	else if (tetriminos->type && tetriminos->type == 'i')
		dimensions = 4;
	else
		dimensions = 3;
	flag = 0; //Will be set to one when answer grid is complete
	answer_grid = NULL;
	while (flag == 0)
	{
		if (answer_grid != NULL) 
			answer_grid = ft_alloc_answer_grid(dimensions, answer_grid);
		else //Intial Condition. First loop only
			answer_grid = ft_alloc_answer_grid(dimensions, NULL);
		answer_grid = ft_placeable(tetriminos, answer_grid, dimensions, &flag); //Entry into placement logic. Always begins with tetrmino 'A'
		dimensions++; //If flag is still 0, a larger dimension answer square is needed.

	}
	ft_print_answer_grid(answer_grid, dimensions);
}
