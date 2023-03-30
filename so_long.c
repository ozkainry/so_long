/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozozdemi <ozozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:46:40 by ozozdemi          #+#    #+#             */
/*   Updated: 2023/03/30 15:33:57 by ozozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_no_event(void *var)
{
	(void) var;
	return (0);
}

int	exit_game(t_var *var)
{
	int	i;

	i = 0;
	if (var->map != NULL)
	{
		while (var->map[i] != NULL)
		{
			free(var->map[i]);
			i++;
		}
		free(var->map);
		mlx_destroy_protected(var->mlx, var->img.img_bush);
		mlx_destroy_protected(var->mlx, var->img.img_grass);
		mlx_destroy_protected(var->mlx, var->img.img_char_down);
		mlx_destroy_protected(var->mlx, var->img.img_char_up);
		mlx_destroy_protected(var->mlx, var->img.img_char_left);
		mlx_destroy_protected(var->mlx, var->img.img_char_right);
		mlx_destroy_protected(var->mlx, var->img.img_coin);
		mlx_destroy_protected(var->mlx, var->img.img_exit);
		mlx_destroy_window(var->mlx, var->mlx_win);
	}
	mlx_destroy_display(var->mlx);
	free(var->mlx);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_var	var;

	if (argc != 2)
		return (error("Error\nNo or too much arguments\n"), 1);
	else
	{
		var.mlx = mlx_init();
		if (!var.mlx)
			return (error("Error\nNo environment\n"), 1);
		set_var(&var);
		var.map = get_map(&var, argv);
		if (!var.map)
			exit_game(&var);
		var.mlx_win = mlx_new_window(var.mlx, 64 * var.width, 64 * var.height,
				"so_long");
		set_img(&var);
		img_map(&var);
		max_coin(&var);
		mlx_loop_hook(var.mlx, &handle_no_event, &var);
		mlx_hook(var.mlx_win, 17, 0, &exit_game, &var);
		mlx_key_hook(var.mlx_win, &move_char, &var);
		mlx_loop(var.mlx);
	}
	return (0);
}
