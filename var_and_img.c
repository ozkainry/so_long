/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_and_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozozdemi <ozozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:58:44 by ozozdemi          #+#    #+#             */
/*   Updated: 2023/03/30 23:07:32 by ozozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_var(t_var *var)
{
	var->count_c = 0;
	var->count_p = 0;
	var->count_e = 0;
	var->moves = 0;
}

void	set_path(t_var *var)
{
	var->img.bush = "images/bush.xpm";
	var->img.grass = "images/grass.xpm";
	var->img.char_down = "images/char_down.xpm";
	var->img.char_up = "images/char_up.xpm";
	var->img.char_right = "images/char_right.xpm";
	var->img.char_left = "images/char_left.xpm";
	var->img.coin = "images/coin.xpm";
	var->img.exit = "images/door.xpm";
}

void	set_img(t_var *var)
{
	set_path(var);
	var->img.height = 64;
	var->img.width = 64;
	var->img.img_bush = mlx_xpm_file_to_image(var->mlx, var->img.bush,
			&var->img.width, &var->img.height);
	var->img.img_grass = mlx_xpm_file_to_image(var->mlx, var->img.grass,
			&var->img.width, &var->img.height);
	var->img.img_char_down = mlx_xpm_file_to_image(var->mlx, var->img.char_down,
			&var->img.width, &var->img.height);
	var->img.img_char_up = mlx_xpm_file_to_image(var->mlx, var->img.char_up,
			&var->img.width, &var->img.height);
	var->img.img_char_right = mlx_xpm_file_to_image(var->mlx,
			var->img.char_right, &var->img.width, &var->img.height);
	var->img.img_char_left = mlx_xpm_file_to_image(var->mlx, var->img.char_left,
			&var->img.width, &var->img.height);
	var->img.img_coin = mlx_xpm_file_to_image(var->mlx, var->img.coin,
			&var->img.width, &var->img.height);
	var->img.img_exit = mlx_xpm_file_to_image(var->mlx, var->img.exit,
			&var->img.width, &var->img.height);
	if (!check_image(var))
	{
		error("Error\nCan't access to assets\n");
		exit_game(var);
	}
}

void	img_map(t_var *var)
{
	int	i;
	int	j;

	i = 0;
	while (var->map[i])
	{
		j = 0;
		while (var->map[i][j])
		{
			if (var->map[i][j] == '1')
				print_img(var, var->img.img_bush, i, j);
			if (var->map[i][j] == '0')
				print_img(var, var->img.img_grass, i, j);
			if (var->map[i][j] == 'P')
				print_img(var, var->img.img_char_down, i, j);
			if (var->map[i][j] == 'C')
				print_img(var, var->img.img_coin, i, j);
			if (var->map[i][j] == 'E')
				print_img(var, var->img.img_exit, i, j);
			j++;
		}
		i++;
	}
}

int	check_image(t_var *var)
{
	if (var->img.img_bush && var->img.img_grass && var->img.img_char_down
		&& var->img.img_char_up && var->img.img_char_right
		&& var->img.img_char_left && var->img.img_coin && var->img.img_exit)
		return (1);
	return (0);
}

void	mlx_destroy_protected(void *mlx_ptr, void *img_ptr)
{
	if (img_ptr)
	{
		mlx_destroy_image(mlx_ptr, img_ptr);
	}
}
