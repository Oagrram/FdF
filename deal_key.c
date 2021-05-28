/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elfetoua <elfetoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 17:55:19 by elfetoua          #+#    #+#             */
/*   Updated: 2020/02/29 00:19:01 by elfetoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		print_menu(void *con_ptr, void *win_ptr)
{
	mlx_string_put((void *)con_ptr, (void *)win_ptr, 10, 10,
	0xffffff, "(projection) 1/2 [Paralell/ISO]");
	mlx_string_put((void *)con_ptr, (void *)win_ptr, 10, 40,
	0xffffff, "+/- (zoom)");
	mlx_string_put((void *)con_ptr, (void *)win_ptr, 10, 70,
	0xffffff, "UP/DOWN/LEFT/RIGHT (position)");
	mlx_string_put((void *)con_ptr, (void *)win_ptr, 10, 100,
	0xffffff, "c (center)");
	mlx_string_put((void *)con_ptr, (void *)win_ptr, 10, 130,
	0xffffff, "z (speed_up)");
	mlx_string_put((void *)con_ptr, (void *)win_ptr, 10, 160,
	0xffffff, "x (speed_down)");
	mlx_string_put((void *)con_ptr, (void *)win_ptr, 10, 190,
	RED, "R (color)");
	mlx_string_put((void *)con_ptr, (void *)win_ptr, 10, 220,
	BLUE, "B (color)");
	mlx_string_put((void *)con_ptr, (void *)win_ptr, 10, 250,
	ORANGE, "O (color)");
	mlx_string_put((void *)con_ptr, (void *)win_ptr, 10, 280,
	GREEN, "G (color)");
}

int			key_press_flech(int key, t_ivec2 *offset, void *env, int a)
{
	if (key == 123 || key == 124)
	{
		offset->x += (key == 123) ? -(a) : (a);
		((t_env*)env)->offset.x = offset->x;
	}
	if (key == 126 || key == 125)
	{
		offset->y += (key == 126) ? -a : a;
		((t_env*)env)->offset.y = offset->y;
	}
	return (0);
}

int			key_press_color(int key, int *color)
{
	if (key == 31)
		*color = ORANGE;
	if (key == 15)
		*color = RED;
	if (key == 11)
		*color = BLUE;
	if (key == 5)
		*color = GREEN;
	return (0);
}

int			key_press_exit(int key, t_env *env)
{
	if (key == 53)
	{
		mlx_destroy_window(env->win->con_ptr, env->win->win_ptr);
		exit_env((t_env*)env);
	}
	return (0);
}

int			deal_key(int key, void *env)
{
	int				color;
	static	t_ivec2	offset;
	static	int		a;

	color = WHITE;
	key_press_color(key, &color);
	if (a == 0)
		a = 3;
	key_press_exit(key, env);
	if (key == 84)
		((t_env*)env)->transf = 2;
	if (key == 83)
		((t_env*)env)->transf = 1;
	if (key == 69)
		((t_env*)env)->zoom *= 2;
	if (key == 78 && ((t_env*)env)->zoom != 1)
		((t_env*)env)->zoom /= 2;
	if (key == 6)
		a *= 2;
	if (key == 7)
		a /= 2;
	key_press_flech(key, &offset, env, a);
	if (key == 8)
		center(env, &offset);
	return (clear_and_draw((t_env*)env, color));
}
