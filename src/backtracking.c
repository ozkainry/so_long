/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozozdemi <ozozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:07:14 by ozozdemi          #+#    #+#             */
/*   Updated: 2023/06/01 14:29:42 by ozozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**copy_map(t_var *var)
{
	char	**cmap;
	int		i;

	i = 0;
	while (var->map[i])
	i++;
	cmap = malloc(sizeof(char *) * (i + 1));
	if (!cmap)
		return (NULL);
	i = 0;
	while (var->map[i])
	{
		cmap[i] = ft_strdup(var->map[i]);
		i++;
	}
	cmap[i] = NULL;
	return (cmap);
}

int	is_inside_map(t_point p, t_var *var)
{
	return (p.x >= 0 && p.y >= 0 && p.x < var->height && p.y < var->width);
}

void	fill_flood(t_point p, char **map, t_var *var)
{
	const t_point		up = {p.x - 1, p.y};
	const t_point		down = {p.x + 1, p.y};
	const t_point		left = {p.x, p.y - 1};
	const t_point		right = {p.x, p.y + 1};

	if (!is_inside_map(p, var) || map[p.x][p.y] == '1' || map[p.x][p.y] == 'M')
		return ;
	if (map[p.x][p.y] == 'E')
	{
		map[p.x][p.y] = 'M';
		return ;
	}
	map[p.x][p.y] = 'M';
	fill_flood(right, map, var);
	fill_flood(down, map, var);
	fill_flood(left, map, var);
	fill_flood(up, map, var);
}

int	check_cmap(t_var *var)
{
	char	**cmap;
	int		i;
	int		j;

	i = 0;
	cmap = copy_map(var);
	fill_flood((t_point){var->x, var->y}, cmap, var);
	while (cmap[i])
	{
		j = 0;
		while (cmap[i][j])
		{
			if (cmap[i][j] == 'E' || cmap[i][j] == 'C')
				return (free_cmap(cmap), 0);
			j++;
		}
		i++;
	}
	free_cmap(cmap);
	return (1);
}
