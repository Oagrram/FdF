/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oagrram <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 11:42:00 by oagrram           #+#    #+#             */
/*   Updated: 2020/02/29 11:42:04 by oagrram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include <stdio.h>
# include <mlx.h>
# include <math.h>
# define WHITE 0X00FFFFFF
# define ORANGE 0X00FFA500
# define PINK 0X00FF00FF
# define RED 0XFF0000
# define BLUE 0X0000FF
# define GREEN 0X006400
# define SIZE1 1000
# define SIZE2 1600

typedef struct	s_ivec2
{
	int			x;
	int			y;
}				t_ivec2;

typedef struct	s_fvec2
{
	double		x;
	double		y;
}				t_fvec2;

typedef struct	s_point
{
	double		x;
	double		y;
	double		z;
	int			color;
}				t_point;

typedef struct	s_map
{
	int			cols;
	int			rows;
	int			size;
	t_point		*content;
}				t_map;

typedef struct	s_win
{
	void		*con_ptr;
	void		*win_ptr;
	t_ivec2		size;
	char		*title;
}				t_win;

typedef struct	s_env
{
	void		*con_ptr;
	t_win		*win;
	t_map		*map;
	t_ivec2		offset;
	int			zoom;
	int			transf;
}				t_env;

int				deal_key(int key, void *env);
int				center(t_env *env, t_ivec2 *offset);
int				hex_dec(char *hex_val);
void			ft_setup(t_env *env, int i);
void			drawline(t_env *env, t_point p1, t_point p2, int color);
void			ft_draw_map(t_env *env, int color);
void			ft_transform(t_point *p, t_env *env);
void			exit_env(t_env *env);
int				clear_and_draw(t_env *env, int color);
void			print_menu(void	*con_ptr, void	*win_ptr);
void			fill_data(t_map *map, int index, t_ivec2 coords);
int				fill_content(int fd, t_map *map, int index);
void			free_line_split(char *line, char **split);
#endif
