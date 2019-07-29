/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 19:25:11 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/07/26 19:25:11 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "filler.h"

void		ft_first_case(t_fill *fill, t_fig *fig, int i, int j)
{
	int x;
	int y;

	y = 0;
	while (y + fig->fig_y <= j)
	{
		x = i;
		while (x + fig->fig_x <= fill->x)
		{
			if (ft_podstanovka(fill, fig, x, y) == 1)
			{
				ft_target_better_value(fill);
				ft_free_intermediate(fill);
			}
			else
				ft_free_intermediate(fill);
			x++;
		}
		y++;
	}
}

void		ft_second_case(t_fill *fill, t_fig *fig, int i, int j)
{
	int x;
	int y;

	y = 0;
	while (y + fig->fig_y <= j)
	{
		x = i;
		while (x + fig->fig_x <= fill->x / 2 + 1)
		{
			if (ft_podstanovka(fill, fig, x, y) == 1)
			{
				ft_target_better_value(fill);
				ft_free_intermediate(fill);
			}
			else
				ft_free_intermediate(fill);
			x++;
		}
		y++;
	}
}

void		ft_third_case(t_fill *fill, t_fig *fig, int i, int j)
{
	int x;
	int y;

	y = fill->y;
	while (y - fig->fig_y >= j)
	{
		x = i;
		while (x + fig->fig_x <= fill->x)
		{
			if (ft_podstanovka(fill, fig, x, y - fig->fig_y) == 1)
			{
				ft_target_better_value(fill);
				ft_free_intermediate(fill);
			}
			else
				ft_free_intermediate(fill);
			x++;
		}
		y--;
	}
}

void		ft_fourth_case(t_fill *fill, t_fig *fig, int i, int j)
{
	int x;
	int y;

	y = fill->y;
	while (y - fig->fig_y >= j)
	{
		x = i;
		while (x + fig->fig_x <= fill->x / 2 + 1)
		{
			if (ft_podstanovka(fill, fig, x, y - fig->fig_y) == 1)
			{
				ft_target_better_value(fill);
				ft_free_intermediate(fill);
			}
			else
				ft_free_intermediate(fill);
			x++;
		}
		y--;
	}
}
