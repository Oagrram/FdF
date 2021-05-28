/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oagrram <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 12:00:18 by oagrram           #+#    #+#             */
/*   Updated: 2020/02/29 12:00:19 by oagrram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_data(t_map *map, int index, t_ivec2 coords)
{
	map->content[index].x = (double)coords.x;
	map->content[index].y = (double)coords.y;
	map->content[index].color = WHITE;
}

int		fill_content(int fd, t_map *map, int index)
{
	char	*line;
	t_ivec2 coords;
	char	**split;
	char	*color;

	coords.y = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (!(split = ft_strsplit(line, ' ')))
			exit(1);
		coords.x = 0;
		while (split[coords.x] != NULL)
		{
			index = coords.x + coords.y * map->cols;
			fill_data(map, index, coords);
			map->content[index].z = ft_atoi(split[coords.x]);
			if ((color = ft_strchr(split[coords.x], ',')))
				map->content[index].color = hex_dec(color + 2);
			coords.x++;
		}
		free(line);
		ft_bonus_freedoubledem(split);
		coords.y++;
	}
	return (0);
}
