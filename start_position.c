/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_position.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 20:16:35 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/07/23 20:16:35 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "filler.h"

void	ft_start_position(t_fill *fill)
{
	int i;
	int j;

	i = 0;
	while (i < fill->y)
	{
		j = 0;
		while (j < fill->x)
		{
			if (fill->map[i][j] == fill->c)
			{
				fill->start_y = i;
				fill->start_x = j;
			}
			if (fill->map[i][j] == fill->enemy)
			{
				fill->start_en_y = i;
				fill->start_en_x = j;
			}
			j++;
		}
		i++;
	}
}

int	ft_analyse_position(t_fill *fill, int x, int y)
{
	double x_middle;
	double y_middle;

	x_middle = (fill->x - 1) / 2;
	y_middle = (fill->y - 1) / 2;
	if (x_middle >= x && y_middle >= y)
		return (1);
	else if (x_middle < x && y_middle >= y)
		return (2);
	else if (x_middle >= x && y_middle < y)
		return (3);
	else
		return (4);
}
