/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozozdemi <ozozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:19:57 by ozozdemi          #+#    #+#             */
/*   Updated: 2023/04/03 17:55:18 by ozozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	up(t_var *var)
{
	var->newx = var->x - 1;
	if (var->map[var->x - 1][var->y] == 'E' && var->coin != var->maxcoin)
		return ;
	if (var->map[var->newx][var->y] == '0' || var->map[var->newx][var->y] == 'P'
		|| var->map[var->newx][var->y] == 'C')
	{
		if (var->map[var->newx][var->y] == 'C')
		{
			var->coin++;
			ft_printf("Number of pokeballs : %d/%d\n", var->coin, var->maxcoin);
			var->map[var->newx][var->y] = '0';
		}
		print_img(var, var->img.img_char_up, var->newx, var->y);
		print_img(var, var->img.img_grass, var->x, var->y);
		var->moves++;
		ft_printf("Number of movements : %d\n", var->moves);
	}
	if (var->map[var->newx][var->y] == 'E' && var->coin == var->maxcoin)
	{
		var->moves++;
		ft_printf("Number of movements : %d\n", var->moves);
		ft_printf("Congratulations you've won!\n");
		exit_game(var);
	}
	var->x = var->newx;
}

void	down(t_var *var)
{
	var->newx = var->x + 1;
	if (var->map[var->x + 1][var->y] == 'E' && var->coin != var->maxcoin)
		return ;
	if (var->map[var->newx][var->y] == '0' || var->map[var->newx][var->y] == 'P'
		|| var->map[var->newx][var->y] == 'C')
	{
		if (var->map[var->newx][var->y] == 'C')
		{
			var->coin++;
			ft_printf("Number of pokeballs : %d/%d\n", var->coin, var->maxcoin);
			var->map[var->newx][var->y] = '0';
		}
		print_img(var, var->img.img_char_down, var->newx, var->y);
		print_img(var, var->img.img_grass, var->x, var->y);
		var->moves++;
		ft_printf("Number of movements : %d\n", var->moves);
	}
	if (var->map[var->newx][var->y] == 'E' && var->coin == var->maxcoin)
	{
		var->moves++;
		ft_printf("Number of movements : %d\n", var->moves);
		ft_printf("Congratulations you've won!\n");
		exit_game(var);
	}
	var->x = var->newx;
}

void	left(t_var *var)
{
	var->newy = var->y - 1;
	if (var->map[var->x][var->y - 1] == 'E' && var->coin != var->maxcoin)
		return ;
	if (var->map[var->x][var->newy] == '0' || var->map[var->x][var->newy] == 'P'
		|| var->map[var->x][var->newy] == 'C')
	{
		if (var->map[var->x][var->newy] == 'C')
		{
			var->coin++;
			ft_printf("Number of pokeballs : %d/%d\n", var->coin, var->maxcoin);
			var->map[var->x][var->newy] = '0';
		}
		print_img(var, var->img.img_char_left, var->x, var->newy);
		print_img(var, var->img.img_grass, var->x, var->y);
		var->moves++;
		ft_printf("Number of movements : %d\n", var->moves);
	}
	if (var->map[var->x][var->newy] == 'E' && var->coin == var->maxcoin)
	{
		var->moves++;
		ft_printf("Number of movements : %d\n", var->moves);
		ft_printf("Congratulations you've won!\n");
		exit_game(var);
	}
	var->y = var->newy;
}

void	right(t_var *var)
{
	var->newy = var->y + 1;
	if (var->map[var->x][var->y + 1] == 'E' && var->coin != var->maxcoin)
		return ;
	if (var->map[var->x][var->newy] == '0' || var->map[var->x][var->newy] == 'P'
		|| var->map[var->x][var->newy] == 'C')
	{
		if (var->map[var->x][var->newy] == 'C')
		{
			var->coin++;
			ft_printf("Number of pokeballs : %d/%d\n", var->coin, var->maxcoin);
			var->map[var->x][var->newy] = '0';
		}
		print_img(var, var->img.img_char_right, var->x, var->newy);
		print_img(var, var->img.img_grass, var->x, var->y);
		var->moves++;
		ft_printf("Number of movements : %d\n", var->moves);
	}
	if (var->map[var->x][var->newy] == 'E' && var->coin == var->maxcoin)
	{
		var->moves++;
		ft_printf("Number of movements : %d\n", var->moves);
		ft_printf("Congratulations you've won!\n");
		exit_game(var);
	}
	var->y = var->newy;
}
