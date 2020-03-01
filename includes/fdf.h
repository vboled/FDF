/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 11:41:07 by gweasley          #+#    #+#             */
/*   Updated: 2019/12/05 11:42:14 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "get_next_line.h"
# include <mlx.h>
# include <math.h>

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
	int				color;
}					t_point;

typedef	struct		s_min_max
{
	int				*min;
	int				*max;
}					t_min_max;

typedef struct		s_count
{
	int				count_of_point;
	int				count_of_str;
	void			*mlx;
	void			*win;
	t_point			**map;
	t_point			**map_new;
	double			*fx;
	double			*fy;
	double			*fz;
	int				*shift_x;
	int				*shift_y;
	double			*scale;
	double			*stretch;
	t_min_max		*extr;
	double			*r;
}					t_count;

typedef struct		s_line
{
	int				dx;
	int				dy;
	int				sx;
	int				sy;
}					t_line;

void				str_file_count(char *filename, t_count *c);
t_point				**get_map(char *filename, t_count c);
int					is_suitable(char *line, int *num_of_point);
void				put_in_points(t_point *map, char *line, int i, t_count c);
int					deal_hook(int key, void *param);
void				print_field(t_count *c);
void				print_field1(t_count *c);
void				erase_and_create(t_count *c);
void				p_line(t_count c, t_point a, t_point b);
void				rot(t_count *c);
int					get_map1(char *filename, t_count *c);
int					allocate_mem(t_count *c);
void				erase_struct(t_count *c);
void				free_struct(t_count *c);
void				shift(t_count *c, int key);
void				rotation(t_count *c, int key);
void				bias(t_count *c);
void				iso(t_count *c);
void				centering(t_count *c, int key);
void				scaling(t_count *c, int key);
void				scale(t_count *c);
void				inverse(t_count *c);
void				stretch(t_count *c);
void				stretching(t_count *c, int key);
void				center(t_count *c);
void				put_color(t_count *c);
int					get_color(int begin, int end, double percent);
int					mouse_hook(int key, void *param);
int					my_atoi(char **str);
#endif
