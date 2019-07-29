/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_coordinate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 16:28:10 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/07/25 16:28:10 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "filler.h"

void	ft_write_coordinate(t_fill *fill)
{
	ft_putnbr(fill->y_write);
	write(1, " ", 1);
	ft_putnbr(fill->x_write);
	write(1, "\n", 1);
}
