/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_parametres.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 17:09:30 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/07/23 17:09:30 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "filler.h"

void	ft_copy_figure(t_fig *fig, int file)
{
	char *line;
	int i;

	i = 0;
	while (i < fig->fig_y)
	{
		get_next_line(file, &line);
		fig->figure[i] = ft_strcpy(fig->figure[i], (const char *)line);
		i++;
		ft_strdel(&line);
	}
}

void	ft_figure_malloc(t_fig *fig)
{
	int i;

	i = 0;
	fig->figure = (char**)malloc(sizeof(char*) * (fig->fig_y + 1));
	while (i < fig->fig_y)
	{
		fig->figure[i] = ft_strnew(fig->fig_x);
		i++;
	}
}

void	ft_figure_parametres_calc(t_fig *fig)
{
	fig->width = fig->xmax - fig->xmin + 1;
	fig->height = fig->ymax - fig->ymin + 1;
}

void	ft_figure_parametres(t_fig *fig)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < fig->fig_y)
	{
		i = 0;
		while (i < fig->fig_x)
		{
			if (fig->figure[j][i] == '*' && fig->ymin == -1)
			{
				fig->ymin = j;
				fig->ymax = j;
				fig->xmin = i;
				fig->xmax = i;
			}
			if (fig->figure[j][i] == '*' && j > fig->ymax)
				fig->ymax = j;
			if (fig->figure[j][i] == '*' && i > fig->xmax)
				fig->xmax = i;
			if (fig->figure[j][i] == '*' && i < fig->xmin)
				fig->xmin = i;
			i++;
		}
		j++;
	}
}

void	ft_find_piece(t_fill *fill, t_fig *fig, char *line, int file)
{
	ft_fill_column_and_row(fill, fig, line, 1);
	ft_figure_malloc(fig);
	ft_copy_figure(fig, file);
	ft_figure_parametres(fig);
	ft_figure_parametres_calc(fig);
//	int x = 0;
//	while (x < fig->fig_y)
//	{
//		ft_putstr(fig->figure[x]);
//		write(1, "\n", 1);
//		x++;
//	}
}
