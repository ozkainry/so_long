/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozozdemi <ozozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:34:12 by ozozdemi          #+#    #+#             */
/*   Updated: 2023/04/03 17:55:21 by ozozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	*free_map(t_var *var)
{
	int	i;

	i = 0;
	while (var->map[i] != NULL)
	{
		free(var->map[i]);
		i++;
	}
	free(var->map);
	var->map = NULL;
	return (0);
}

char	**read_map(t_var *var)
{
	char	*str;
	char	*tmp;

	tmp = ft_strdup("so_long");
	str = get_next_line(var->fd);
	while (tmp != NULL)
	{
		if (ft_strlen(tmp) < 4 || ft_strlen(str) < 4)
			return (free(str), free(tmp),
				error("Error\nThere's an empty line in map\n"), NULL);
		free(tmp);
		tmp = get_next_line(var->fd);
		if (!tmp)
			break ;
		str = join(str, tmp);
	}
	var->map = ft_split(str, '\n');
	search_player(var);
	return (free(tmp), free(str), var->map);
}

char	**parsing(t_var *var)
{
	int	i;

	i = 1;
	var->map = read_map(var);
	if (!var->map)
		return (NULL);
	check_content(var);
	if (!check_map(var->map))
		return (free_map(var));
	if (!check_line(var->map[0], '1'))
		return (free_map(var));
	while (var->map[i] != NULL)
	{
		if (!check_column(var->map[i], '1', var))
			return (free_map(var));
		else if (!check_count(var))
			return (free_map(var));
		i++;
	}
	var->height = i;
	if (!check_line(var->map[i - 1], '1'))
		return (free_map(var));
	if (!check_cmap(var))
		return (error("Error\nExit or collectible unreachable\n"), free_map(var));
	return (var->map);
}

char	**get_map(t_var *var, char **argv)
{
	if (ft_strrchr(argv[1], '/'))
	{
		if (ft_strlen(ft_strrchr(argv[1], '/') + 1) < 5)
			return (error("Error\nMap is wrong\n"));
	}
	if (sl_strchr(argv[1], ".ber") == 0)
		return (error("Error\nMap must be a .ber\n"));
	else
	{
		var->fd = open(argv[1], O_RDONLY);
		if (var->fd > 0)
			var->map = parsing(var);
		else
		{
			return (error("Error\nCan't open file\n"));
		}
		if ((var->count_c == 0 || var->count_e != 1 || var->count_p != 1)
			&& var->map != NULL)
		{
			return (error("Error\nNeed 1 Exit, 1 Player and atleast 1 Coin\n"),
				free_map(var));
		}
	}
	return (var->map);
}
