/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 17:15:05 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/07/22 17:15:05 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "filler.h"

int		ft_distribution(t_fill *fill, t_fig *fig, int file)
{
	char *line;

	while (get_next_line(file, &line) > 0)
	{
		if (ft_strncmp(line, "Plateau", 6) == 0)
		{
			ft_1_init(fill);
			ft_map_gen(fill, fig, line, file);
			ft_strdel(&line);
		}
		else if (ft_strncmp(line, "Piece", 4) == 0)
		{
			ft_2_init(fig);
			ft_find_piece(fill, fig, line, file);
			return (1);
		}
		else
			ft_strdel(&line);
	}
	return (0);
}

int		main()
{
	t_fill *fill;
	t_fig *fig;
	int file;

	file = open("/Users/lgeorgia/fillergoodalg/sources/file.txt", O_RDONLY);
//	file = 0;
	fill = (t_fill*)malloc(sizeof(t_fill) * 1);
	fig = (t_fig*)malloc(sizeof(t_fig) * 1);
	ft_fill_init(fill, fig);
	get_player(fill, file);
	while (1)
	{
		if (ft_distribution(fill, fig, file) == 1)
		{
			if (ft_find_good_place(fill, fig) == 1)
			{
				ft_write_coordinate(fill);
			}
		}
	}
}
