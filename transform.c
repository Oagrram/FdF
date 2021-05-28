/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elfetoua <elfetoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 04:51:10 by elfetoua          #+#    #+#             */
/*   Updated: 2020/02/23 20:40:02 by elfetoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_transform(t_point *p, t_env *env)
{
	t_point	previous;

	if (env->transf == 2)
	{
		previous = *p;
		p->x = (previous.x - previous.y) * cos(0.523599);
		p->y = -p->z + (previous.x + previous.y) * sin(0.523599);
	}
	p->x = p->x * env->zoom + env->offset.x;
	p->y = p->y * env->zoom + env->offset.y;
}
