/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_figure.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 19:55:52 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/07/23 19:55:52 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "filler.h"

void	ft_free_intermediate(t_fill *fill)
{
	fill->inter_x = 0;
	fill->inter_y = 0;
	fill->count_pnt = 0;
}

void	ft_full_value_intermediate(t_fill *fill, t_fig *fig, int y, int x)
{
	if (fill->position == 1 || fill->position == 3)
	{
		fill->inter_x = fig->xmax - x;
	}
	else
		fill->inter_x = x - fig->xmin;
	if (fill->position == 1 || fill->position == 2)
	{
		fill->inter_y = y - fig->ymin;
	}
	else
		fill->inter_y = fig->ymax - y;
	fill->count_pnt++;
}

void	ft_new_difxy(t_fill *fill, int difx, int dify)
{
	if (fill->dif_y > dify && fill->dif_x > difx)
	{
		fill->y_write = fill->y_fin;
		fill->x_write = fill->x_fin;
		fill->dif_y = dify;
		fill->dif_x = difx;
		return ;
	}
	if (fill->dif_y > dify)
	{
		fill->y_write = fill->y_fin;
		fill->x_write = fill->x_fin;
		fill->dif_y = dify;
		fill->dif_x = difx;
	}
}

void	ft_check_better_value(t_fill *fill)
{
	int dify;
	int difx;

	dify = fill->inter_y;
	difx = fill->inter_x;
	if (fill->dif_x == -1 && fill->dif_y == -1)
	{
		fill->dif_x = difx;
		fill->dif_y = dify;
		fill->y_write = fill->y_fin;
		fill->x_write = fill->x_fin;
		return ;
	}
	ft_new_difxy(fill, difx, dify);
}

int		ft_podstanovka(t_fill *fill, t_fig *fig, int map_x, int map_y)
{
	int x;
	int y;

	y = 0;
	while (y < fig->fig_y)
	{
		x = 0;
		while (x < fig->fig_x)
		{
			if ((fill->map[map_y + y][map_x + x] == fill->c || fill->map[map_y + y][map_x + x] == fill->c1)
			&& fig->figure[y][x] == '*')
			{
				ft_full_value_intermediate(fill, fig, y, x);
			}
			if ((fill->map[map_y + y][map_x + x] == fill->enemy || fill->map[map_y + y][map_x + x] == fill->enemy2)
			&& fig->figure[y][x] == '*')
			{
				return (0);
			}
			x++;
		}
		y++;
	}
	if (fill->count_pnt == 1)
	{
		fill->i++;
		fill->x_fin = map_x;
		fill->y_fin	= map_y;
		return (1);
	}
	else
		return (0);
}

void		ft_going_on_the_map(t_fill *fill, t_fig *fig)
{
	int x;
	int y;

	y = 0;
	while (y + fig->fig_y <= fill->y)
	{
		x = 0;
		while (x + fig->fig_x <= fill->x)
		{
			if (ft_podstanovka(fill, fig, x, y) == 1)
			{
				ft_check_better_value(fill);
				ft_free_intermediate(fill);
			}
			else
				ft_free_intermediate(fill);
			x++;
		}
		y++;
	}
}

int		ft_find_good_place(t_fill *fill, t_fig *fig)
{
	if (fill->position == 3 || fill->position == 4)
		ft_check_target_34(fill);
	else
		ft_check_target_12(fill);
	if (fill->target == 1)
	{
		if (ft_if_target_is_reached(fill, fig) == 1)
			return (1);
		else
		{
			ft_going_on_the_map(fill, fig);
			if (fill->i == 0)
				exit(1);
			else
				return (1);
		}
	}
	else
		ft_going_on_the_map(fill, fig);
	if (fill->i == 0)
	{
		exit(1);
	}
	else
		return (1);
}
