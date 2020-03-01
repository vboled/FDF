/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_work.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 15:23:21 by gweasley          #+#    #+#             */
/*   Updated: 2020/02/16 15:23:22 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	erase_and_create(t_count *c)
{
	mlx_clear_window(c->mlx, c->win);
	stretch(c);
	center(c);
	rot(c);
	bias(c);
	scale(c);
	print_field(c);
}

int		deal_hook(int key, void *param)
{
	if (key == 53)
	{
		write(1, "EXIT", 4);
		free_struct(param);
		exit(0);
	}
	if (key == 69 || key == 78)
		scaling(param, key);
	if (key == 49)
		iso(param);
	if (key == 115 || key == 119)
		centering(param, key);
	if ((key >= 0 && key <= 2) || (key >= 6 && key <= 8))
		rotation(param, key);
	if (key >= 123 && key <= 126)
		shift(param, key);
	if (key == 34)
		inverse(param);
	if (key == 116 || key == 121)
		stretching(param, key);
	erase_and_create(param);
	return (0);
}
