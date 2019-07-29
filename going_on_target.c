/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   going_on_target.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 17:39:56 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/07/26 17:39:56 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "filler.h"

void	ft_target_difxy(t_fill *fill, int difx, int dify)
{
	if (fill->dif_x > difx)
	{
		fill->y_write = fill->y_fin;
		fill->x_write = fill->x_fin;
		fill->dif_y = dify;
		fill->dif_x = difx;
		return ;
	}
}

void	ft_target_better_value(t_fill *fill)
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
	ft_target_difxy(fill, difx, dify);
}

int	ft_if_target_is_reached(t_fill *fill, t_fig *fig)
{
	int x;
	int y;

	if (fill->position == 1 || fill->position == 2)
	{
		y = fill->place_enemy - 1;
		if (fill->position == 1 || fill->position == 3)
		{
			x = fill->x / 2;
			ft_first_case(fill, fig, x, y);
		}
		else
		{
			x = 0;
			ft_second_case(fill, fig, x, y);
		}
	}
	else
	{
		y = fill->place_enemy + 1;
		if (fill->position == 1 || fill->position == 3)
		{
			x = fill->x / 2;
			ft_third_case(fill, fig, x, y);
		}
		else
		{
			x = 0;
			ft_fourth_case(fill, fig, x, y);
		}
	}
	if (fill->y_write == -1)
		return (0);
	else
		return (1);
}
