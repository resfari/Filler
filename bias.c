/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bias.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 19:52:03 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/07/29 19:52:03 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "filler.h"

void	ft_bias11(t_fill *fill)
{
	int y;
	int x;
	int x1;

	y = fill->start_en_y;
	x1 = fill->start_en_x + 1;
	while (y < fill->y)
	{
		x = x1;
		while (x < fill->x)
		{
			if (fill->map[y][x] == fill->enemy || fill->map[y][x] == fill->enemy2)
			{
				if (x < fill->x - 1)
					fill->blockx1 = x + 1;
				else
					fill->blockx1 = x;
				fill->blocky1 = y;
			}
			x++;
		}
		if (x1 < fill->x - 1)
			x1++;
		y++;
	}
}

void	ft_bias1(t_fill *fill)
{
	int y;
	int x;
	int x1;

	y = fill->start_en_y;
	x1 = fill->start_en_x;
	while (y < fill->y)
	{
		x = x1;
		while (x >= 0)
		{
			if (fill->map[y][x] == fill->enemy || fill->map[y][x] == fill->enemy2)
			{
				if (x - 1 >= 0)
					fill->blockx = x - 1;
				else
					fill->blockx = x;
				fill->blocky = y;
			}
			x--;
		}
		if (x1 < fill->x - 1)
			x1++;
		y++;
	}
	ft_bias11(fill);
}

void	ft_bias22(t_fill *fill)
{
	int y;
	int x;
	int x1;

	y = fill->start_en_y;
	x1 = fill->start_en_x;
	while (y < fill->y)
	{
		x = x1;
		while (x < fill->x)
		{
			if (fill->map[y][x] == fill->enemy || fill->map[y][x] == fill->enemy2)
			{
				if (x < fill->x - 1)
					fill->blockx1 = x + 1;
				else
					fill->blockx1 = x;
				fill->blocky1 = y;
			}
			x++;
		}
		if (x1 >= 0)
			x1--;
		y++;
	}
}

void	ft_bias2(t_fill *fill)
{
	int y;
	int x;
	int x1;

	y = fill->start_en_y;
	x1 = fill->start_en_x - 1;
	while (y < fill->y)
	{
		x = x1;
		while (x >= 0)
		{
			if (fill->map[y][x] == fill->enemy || fill->map[y][x] == fill->enemy2)
			{
				if (x - 1 >= 0)
					fill->blockx = x - 1;
				else
					fill->blockx = x;
				fill->blocky = y;
			}
			x--;
		}
		if (x1 > 0)
			x1--;
		y++;
	}
	ft_bias22(fill);
}

void	ft_bias33(t_fill *fill)
{
	int y;
	int x;
	int x1;

	x1 = fill->start_en_x + 1;
	y = fill->start_en_y;
	while (y >= 0)
	{
		x = x1;
		while (x <= fill->x)
		{
			if (fill->map[y][x] == fill->enemy || fill->map[y][x] == fill->enemy2)
			{
				if (x + 1 < fill->x)
					fill->blockx1 = x + 1;
				else
					fill->blockx1 = x;
				fill->blocky1 = y;
			}
			x++;
		}
		if (x1 < fill->x - 1)
			x1++;
		y--;
	}
}

void	ft_bias3(t_fill *fill)
{
	int y;
	int x;
	int x1;

	y = fill->start_en_y;
	x1 = fill->start_en_x;
	while (y >= 0)
	{
		x = x1;
		while (x >= 0)
		{
			if (fill->map[y][x] == fill->enemy || fill->map[y][x] == fill->enemy2)
			{
				if (x - 1 >= 0)
					fill->blockx = x - 1;
				else
					fill->blockx = x;
				fill->blocky = y;
			}
			x--;
		}
		if (x1 < fill->x - 1)
			x1++;
		y--;
	}
	ft_bias33(fill);
}

void	ft_bias44(t_fill *fill)
{
	int y;
	int x;
	int x1;

	y = fill->start_en_y;
	x1 = fill->start_en_x;
	while (y >= 0)
	{
		x = x1;
		while (x < fill->x)
		{
			if (fill->map[y][x] == fill->enemy || fill->map[y][x] == fill->enemy2)
			{
				if (x + 1 < fill->x)
					fill->blockx1 = x + 1;
				else
					fill->blockx1 = x;
				fill->blocky1 = y;
			}
			x++;
		}
		if (x1 > 0)
			x1--;
		y--;
	}
}

void	ft_bias4(t_fill *fill)
{
	int y;
	int x;
	int x1;

	y = fill->start_en_y;
	x1 = fill->start_en_x;
	while (y >= 0)
	{
		x = x1;
		while (x >= 0)
		{
			if (fill->map[y][x] == fill->enemy || fill->map[y][x] == fill->enemy2)
			{
				if (x - 1 >= 0)
					fill->blockx = x - 1;
				else
					fill->blockx = x;
				fill->blocky = y;
			}
			x--;
		}
		if (x1 > 0)
			x1--;
		y--;
	}
	ft_bias44(fill);
}

void	ft_check_bias_from_start(t_fill *fill)
{
	fill->blockx = fill->start_en_x;
	fill->blocky = fill->start_en_y;
	fill->blockx1 = fill->start_en_x;
	fill->blocky1 = fill->start_en_y;
	if (fill->enemy_position == 1)
	{
		ft_bias1(fill);
	}
	else if (fill->enemy_position == 2)
	{
		ft_bias2(fill);
	}
	else if (fill->enemy_position == 3)
	{
		ft_bias3(fill);
	}
	else
	{
		ft_bias4(fill);
	}
	printf("\npos en = %d\n", fill->enemy_position);
	printf("\ny1 = %d x1 = %d y2 = %d x2 = %d\n", fill->blocky, fill->blockx, fill->blocky1, fill->blockx1);
}