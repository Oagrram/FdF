/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elfetoua <elfetoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 02:40:10 by elfetoua          #+#    #+#             */
/*   Updated: 2020/02/27 21:53:00 by elfetoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		point_insert(t_point *p, int i, t_env *env)
{
	p->x = env->map->content[i].x;
	p->y = env->map->content[i].y;
	p->z = env->map->content[i].z;
	return (0);
}

void	ft_draw_map(t_env *env, int color)
{
	t_point p1;
	t_point	p2;
	int		i;

	i = -1;
	while (++i < env->map->size)
	{
		point_insert(&p1, i, env);
		p1.color = env->map->content[i].color;
		ft_transform(&p1, env);
		if ((i + 1) % env->map->cols)
		{
			point_insert(&p2, i + 1, env);
			p2.color = env->map->content[i + 1].color;
			ft_transform(&p2, env);
			drawline(env, p1, p2, color);
		}
		if ((i + env->map->cols) < env->map->size)
		{
			point_insert(&p2, i + env->map->cols, env);
			p2.color = env->map->content[i + env->map->cols].color;
			ft_transform(&p2, env);
			drawline(env, p1, p2, color);
		}
	}
}
