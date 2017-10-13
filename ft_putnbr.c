/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satkins <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 22:58:39 by satkins           #+#    #+#             */
/*   Updated: 2016/07/19 23:00:46 by satkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_print_index(int nb, int *nbr, int index)
{
	if (nb > 0)
	{
		while (nb > 0)
		{
			nbr[index] = (nb % 10);
			nb = nb / 10;
			index++;
		}
	}
	else
	{
		ft_putchar('-');
		while (nb < 0)
		{
			nbr[index] = (nb % 10) * -1;
			nb = nb / 10;
			index++;
		}
	}
	index--;
	while (index >= 0)
	{
		ft_putchar(nbr[index] + '0');
		index--;
	}
}

void		ft_putnbr(int n)
{
	int		nbr[10];

	if (n == 0)
	{
		ft_putchar('0');
	}
	else
		ft_print_index(n, nbr, 0);
}
