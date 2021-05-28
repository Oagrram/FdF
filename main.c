/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elfetoua <elfetoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 16:51:43 by elfetoua          #+#    #+#             */
/*   Updated: 2020/02/28 23:34:44 by elfetoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		check(int i, int ret, t_map *map, char *filename)
{
	if (ret < 0)
		perror(filename);
	else if (map->size == 0)
		ft_putendl("No data found.");
	else if (i < map->cols)
		ft_putendl("Found wrong line length. Exiting.");
	return (!(ret < 0 || map->size == 0 || i < map->cols));
}

int		check_map_info(t_map *map, char *filename, int fd, int i)
{
	char	*line;
	int		ret;
	char	**split;

	fd = open(filename, O_RDONLY);
	split = NULL;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (!(split = ft_strsplit(line, ' ')))
			exit(1);
		i = -1;
		while (split[++i] != NULL)
			map->size++;
		if (map->rows == 0)
			map->cols = map->size;
		if (i < map->cols)
		{
			free_line_split(line, split);
			break ;
		}
		map->rows += 1;
		free_line_split(line, split);
	}
	close(fd);
	return (check(i, ret, map, filename));
}

void	extract_data(t_map *map, char *filename)
{
	int fd;

	if ((map->content = (t_point*)malloc(sizeof(t_point) * map->size)) == NULL)
		exit(1);
	fd = open(filename, O_RDONLY);
	fill_content(fd, map, 0);
	close(fd);
}

void	env_map(t_map *map, t_env *env)
{
	int		i;

	if ((env->map = (t_map*)malloc(sizeof(t_map))) == NULL)
		exit(1);
	if ((env->map->content =
	(t_point*)malloc(sizeof(t_point) * map->size)) == NULL)
		exit(1);
	if (!env->map->content)
	{
		ft_putendl("null pointer");
		exit(1);
	}
	env->map->cols = map->cols;
	env->map->rows = map->rows;
	env->map->size = map->size;
	i = 0;
	while (i < map->size)
	{
		env->map->content[i] = map->content[i];
		i++;
	}
	free(map->content);
}

int		main(int ac, char **av)
{
	t_map	map;
	t_env	env;

	if (ac == 2)
	{
		ft_bzero((void*)&map, sizeof(t_map));
		if (check_map_info(&map, av[1], 0, 0) > 0)
		{
			extract_data(&map, av[1]);
			ft_setup(&env, map.size);
			env_map(&map, &env);
			mlx_key_hook(env.win->win_ptr, deal_key, (void*)&env);
			mlx_loop(env.con_ptr);
		}
	}
	else
	{
		ft_putstr("Usage : ");
		ft_putstr(av[0]);
		ft_putendl(" <filename> [ case_size z_size ]");
	}
	return (0);
}
