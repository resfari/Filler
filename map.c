/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 20:01:58 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/07/23 20:01:58 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "filler.h"

void	ft_fill_column_and_row(t_fill *fill, t_fig *fig, char *line, int count)
{
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		while (ft_isdigit((int)line[i]))
		{
			if (count == 0)
				fill->y = fill->y * 10 + (line[i] - 48);
			else
				fig->fig_y = fig->fig_y * 10 + (line[i] - 48);
			i++;
			if (line[i] == ' ')
			{
				i++;
				while (ft_isdigit((int)line[i]))
				{
					if (count == 0)
						fill->x = fill->x * 10 + (line[i] - 48);
					else
						fig->fig_x = fig->fig_x * 10 + (line[i] - 48);
					i++;
				}
				return ;
			}
		}
		i++;
	}
}

void	ft_copy_map(t_fill *fill, int file)
{
	int i;
	char *line;

	i = 0;
	get_next_line(file, &line);
	ft_strdel(&line);
	fill->map = (char**)malloc(sizeof(char*) * (fill->y + 1));
	while (i < fill->y)
	{
		get_next_line(file, &line);
		fill->map[i] = ft_strdup((const char *)(&line[4]));
		ft_strdel(&line);
		i++;
	}
}

void	ft_map_gen(t_fill *fill, t_fig *fig, char *line, int file)
{
	if (fill->y == 0 && fill->x == 0)
		ft_fill_column_and_row(fill, fig, line, 0);
	ft_copy_map(fill, file);


	if (fill->start_x == -1)
	{
		ft_start_position(fill);
	}
	if (fill->position == -1)
	{
		fill->enemy_position = ft_analyse_position(fill, fill->start_en_x, fill->start_en_y);
		fill->position = ft_analyse_position(fill, fill->start_x, fill->start_y);
	}
	if (fill->position != -1)
		ft_check_bias_from_start(fill);

//	int x = 0;
//	while (x < fill->y)
//	{
//		ft_putstr(fill->map[x]);
//		write(1, "\n", 1);
//		x++;
//	}
	return ;
}
