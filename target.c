/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 17:00:05 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/07/26 17:00:05 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "filler.h"

void		ft_check_target_34(t_fill *fill)
{
	int y;
	int x;

	y = 0;
	while (y < fill->y)
	{
		x = 0;
		while (x < fill->x)
		{
			if (fill->map[y][x] == fill->c || fill->map[y][x] == fill->c1)
			{
				if (y == 0)
					fill->target = 1;
			}
			if (fill->map[y][x] == fill->enemy || fill->map[y][x] == fill->enemy2)
				fill->place_enemy = y;
			x++;
		}
		y++;
	}
}

void		ft_check_target_12(t_fill *fill)
{
	int y;
	int x;

	y = fill->y - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < fill->x)
		{
			if (fill->map[y][x] == fill->c || fill->map[y][x] == fill->c1)
			{
				if (y == fill->y - 1)
					fill->target = 1;
			}
			if (fill->map[y][x] == fill->enemy || fill->map[y][x] == fill->enemy2)
				fill->place_enemy = y;
			x++;
		}
		y--;
	}
}
