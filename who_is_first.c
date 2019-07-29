/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   who_is_first.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 16:27:50 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/07/23 16:27:50 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "filler.h"

void	wich_player(t_fill *fill)
{
	if (fill->player == 1)
	{

		fill->c = 'O';
		fill->c1 = 'o';
		fill->enemy = 'X';
		fill->enemy2 = 'x';
	}
	if (fill->player == 2)
	{
		fill->c = 'X';
		fill->c1 = 'x';
		fill->enemy = 'O';
		fill->enemy2 = 'o';
	}
}

void			get_player(t_fill *fill, int file)
{
	char		*line;

	get_next_line(file, &line);
	if (ft_strncmp(line, "$$$", 2) == 0 && fill->player == 0)
	{
		if (ft_strstr(line, "p2"))
			fill->player = 2;
		if (ft_strstr(line, "p1"))
			fill->player = 1;
		wich_player(fill);
		printf("%c", fill->enemy2);
	}
	ft_strdel(&line);
}
