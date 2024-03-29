/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozozdemi <ozozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:17:21 by ozozdemi          #+#    #+#             */
/*   Updated: 2023/04/25 13:27:51 by ozozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	search_player(t_var *var)
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
			{
				var->x = i;
				var->y = j;
			}
			j++;
		}
		i++;
	}
}

void	max_coin(t_var *var)
{
	int	i;
	int	j;

	i = 0;
	var->maxcoin = 0;
	var->coin = 0;
	while (var->map[i])
	{
		j = 0;
		while (var->map[i][j])
		{
			if (var->map[i][j] == 'C')
				var->maxcoin++;
			j++;
		}
		i++;
	}
}

int	move_char(int keysym, t_var *var)
{
	if (keysym == XK_Escape)
		exit_game(var);
	if ((keysym == XK_w || keysym == XK_Up)
		&& var->map[var->x - 1][var->y] != '1')
		up(var);
	if ((keysym == XK_s || keysym == XK_Down)
		&& var->map[var->x + 1][var->y] != '1')
		down(var);
	if ((keysym == XK_a || keysym == XK_Left)
		&& var->map[var->x][var->y - 1] != '1')
		left(var);
	if ((keysym == XK_d || keysym == XK_Right)
		&& var->map[var->x][var->y + 1] != '1')
		right(var);
	return (0);
}
