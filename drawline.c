/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elfetoua <elfetoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 02:01:05 by elfetoua          #+#    #+#             */
/*   Updated: 2020/02/27 22:20:13 by elfetoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	drawline(t_env *env, t_point p1, t_point p2, int color)
{
	t_fvec2	delta;
	t_fvec2	step;
	double	max;
	int		i;
	t_win	*win;

	delta.x = p2.x - p1.x;
	delta.y = p2.y - p1.y;
	max = (fabs(delta.x) > fabs(delta.y)) ? fabs(delta.x) : fabs(delta.y);
	step.x = delta.x / max;
	step.y = delta.y / max;
	win = env->win;
	i = -1;
	while (++i <= max)
	{
		if (p1.color == WHITE && (p1.z != 0 && p2.z))
			p1.color = PINK;
		else if (p1.color == WHITE)
			p1.color = color;
		mlx_pixel_put(win->con_ptr, win->win_ptr,
		round(p1.x), round(p1.y), p1.color);
		p1.x += step.x;
		p1.y += step.y;
	}
}
