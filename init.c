/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 20:07:04 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/07/23 20:07:04 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "filler.h"

void	ft_1_init(t_fill *fill)
{
	int y;

	y = 0;
	while (y < fill->y)
	{
		free(fill->map[y]);
		y++;
	}
	fill->i = 0;
	fill->count_pnt = 0;
	fill->inter_x = -1;
	fill->inter_y = -1;
	fill->y_fin = 0;
	fill->x_fin = 0;
	fill->x_write = -1;
	fill->y_write = -1;
	fill->dif_x = -1;
	fill->dif_y = -1;
}

void	ft_2_init(t_fig *fig)
{
	int y;

	y = 0;
	while (y < fig->fig_y)
	{
		free(fig->figure[y]);
		y++;
	}
	fig->fig_x = 0;
	fig->fig_y = 0;
	fig->size_x = 0;
	fig->size_y = 0;
	fig->ymin = -1;
	fig->ymax = -1;
	fig->xmin = -1;
	fig->xmax = -1;
}

void	ft_fill_init(t_fill *fill, t_fig *fig)
{
	fill->x = 0;
	fill->y = 0;
	fill->i = 0;
	fill->start_y = -1;
	fill->start_x = -1;
	fill->count_pnt = 0;
	fill->inter_x = -1;
	fill->inter_y = -1;
	fill->y_fin = 0;
	fill->x_fin = 0;
	fill->x_write = -1;
	fill->y_write = -1;
	fill->dif_x = -1;
	fill->dif_y = -1;
	fill->target = -1;
	fill->place_enemy = -1;
	fill->player = 0;


	fill->start_en_x = -1;
	fill->position = -1;

	fig->fig_x = 0;
	fig->fig_y = 0;
	fig->size_x = 0;
	fig->size_y = 0;
	fig->ymin = -1;
	fig->ymax = -1;
	fig->xmin = -1;
	fig->xmax = -1;
}
