/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elfetoua <elfetoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 20:12:52 by elfetoua          #+#    #+#             */
/*   Updated: 2020/02/29 00:18:32 by elfetoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_line_split(char *line, char **split)
{
	ft_bonus_freedoubledem(split);
	ft_strdel(&line);
}

void	exit_env(t_env *env)
{
	free(env->win);
	free(env->map->content);
	free(env->map);
	exit(1);
}

int		clear_and_draw(t_env *env, int color)
{
	mlx_clear_window((env)->con_ptr, (env)->win->win_ptr);
	print_menu(((t_env*)env)->con_ptr, ((t_env*)env)->win->win_ptr);
	ft_draw_map(env, color);
	return (0);
}

int		center(t_env *env, t_ivec2 *offset)
{
	offset->x = env->win->size.x / 2 - (env->map->cols * env->zoom / 2);
	offset->y = env->win->size.y / 2 - (env->map->rows * env->zoom / 2);
	env->offset.x = offset->x;
	env->offset.y = offset->y;
	return (1);
}
