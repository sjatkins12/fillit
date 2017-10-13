/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_answer_grid.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satkins <satkins@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 20:20:47 by satkins           #+#    #+#             */
/*   Updated: 2017/10/06 20:20:50 by satkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_print_answer_grid(char **answer_grid, int dimensions)
{
	int		i;

	i = 0;
	while (answer_grid[i] != NULL && i < dimensions)
	{
		ft_putendl(answer_grid[i]);
		free(answer_grid[i]);
		i++;
	}
}
