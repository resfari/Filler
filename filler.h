/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 17:02:21 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/06/19 17:02:21 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stdarg.h>
# include <inttypes.h>
# include <stdint.h>
# include <limits.h>
# include <float.h>
# include <math.h>
# include <stdio.h>

typedef	struct			s_fig
{
	int					fig_y;
	int					fig_x;
	int					size_y;
	int					size_x;
	char				**figure;
	int					ymin;
	int					ymax;
	int					xmin;
	int					xmax;
	int					width;
	int					height;

}						t_fig;

typedef	struct			s_fill
{
	int					i;
	char				c;
	char				c1;
	char				*line;
	int					y;
	int					x;
	int					start_y;
	int					start_x;
	char				**map;
	char				enemy;
	char				enemy2;
	int					position;
	int					enemy_position;
	int					mid_x;
	int					mid_y;
	int 				x_fin;
	int					y_fin;
	int					count_pnt;
	int					inter_y;
	int					inter_x;
	int					dif_x;
	int					dif_y;
	int					y_write;
	int					x_write;
	int					target;
	int					place_enemy;
	int					start_en_y;
	int					start_en_x;
	int					player;
	int					blockx;
	int					blocky;
	int					blockx1;
	int					blocky1;
}						t_fill;

int		who_is_first(t_fill *fill, int file);
void	ft_find_piece(t_fill *fill, t_fig *fig, char *line, int file);
void	ft_fill_column_and_row(t_fill *fill, t_fig *fig, char *line, int count);
void	ft_map_gen(t_fill *fill, t_fig *fig, char *line, int file);
void	ft_figure_malloc(t_fig *fig);
void	ft_start_position(t_fill *fill);
void	ft_fill_init(t_fill *fill, t_fig *fig);
void	ft_map_malloc(t_fill *fill);
int		ft_find_good_place(t_fill *fill, t_fig *fig);
void	ft_write_coordinate(t_fill *fill);
void	ft_1_init(t_fill *fill);
void	ft_2_init(t_fig *fig);
void	ft_check_target_12(t_fill *fill);
void	ft_check_target_34(t_fill *fill);
int		ft_if_target_is_reached(t_fill *fill, t_fig *fig);
void	ft_first_case(t_fill *fill, t_fig *fig, int i, int j);
void	ft_second_case(t_fill *fill, t_fig *fig, int i, int j);
void	ft_third_case(t_fill *fill, t_fig *fig, int i, int j);
void	ft_fourth_case(t_fill *fill, t_fig *fig, int i, int j);
void	ft_target_better_value(t_fill *fill);
void	ft_free_intermediate(t_fill *fill);
int		ft_podstanovka(t_fill *fill, t_fig *fig, int map_x, int map_y);
int		ft_analyse_position(t_fill *fill, int x, int y);
void	get_player(t_fill *fill, int file);
void	ft_check_bias_from_start(t_fill *fill);

#endif
