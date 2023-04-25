/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozozdemi <ozozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:16:53 by ozozdemi          #+#    #+#             */
/*   Updated: 2023/04/25 13:27:45 by ozozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_map(char **map)
{
	size_t	len;
	int		i;

	len = ft_strlen(map[0]);
	i = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
		{
			error("Error\nMap must be a square or a rectangle\n");
			return (0);
		}
		i++;
	}
	return (1);
}

void	check_content(t_var *var)
{
	int	i;
	int	j;

	i = 0;
	while (var->map[i])
	{
		j = 0;
		while (var->map[i][j])
		{
			if (var->map[i][j] == 'P')
				var->count_p += 1;
			if (var->map[i][j] == 'E')
				var->count_e += 1;
			if (var->map[i][j] == 'C')
				var->count_c += 1;
			j++;
		}
		i++;
	}
}

int	check_line(char *map, char c)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] != c)
		{
			error("Error\nMap must be close\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_column(char *map, char c, t_var *var)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	if (map[0] != c || map[i - 1] != c)
	{
		error("Error\nMap must be close\n");
		return (0);
	}
	var->width = i;
	return (1);
}

int	check_count(t_var *var)
{
	int	i;
	int	j;

	i = 0;
	while (var->map[i])
	{
		if (var->count_p > 1 || var->count_e > 1)
		{
			error("Error\nThere's more than 1 player or exit\n");
			return (0);
		}
		j = 0;
		while (var->map[i][++j])
		{
			if (var->map[i][j] != '1' && var->map[i][j] != '0'
				&& var->map[i][j] != 'C' && var->map[i][j] != 'P'
				&& var->map[i][j] != 'E')
			{
				error("Error\nUnknown entity in map\n");
				return (0);
			}
		}
		i++;
	}
	return (1);
}
