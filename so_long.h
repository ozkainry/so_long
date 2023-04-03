/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozozdemi <ozozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:31:15 by ozozdemi          #+#    #+#             */
/*   Updated: 2023/04/03 15:33:39 by ozozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>

typedef struct s_img
{
	void	*img_bush;
	void	*img_grass;
	void	*img_char_down;
	void	*img_char_up;
	void	*img_char_left;
	void	*img_char_right;
	void	*img_coin;
	void	*img_exit;
	char	*char_down;
	char	*char_up;
	char	*char_left;
	char	*char_right;
	char	*grass;
	char	*bush;
	char	*coin;
	char	*exit;
	int		width;
	int		height;
}t_img;

typedef struct s_point
{
	int	x;
	int	y;
}t_point;

typedef struct s_var
{
	int		fd;
	char	**map;
	void	*mlx;
	void	*mlx_win;
	int		count_p;
	int		count_e;
	int		count_c;
	int		height;
	int		width;
	int		x;
	int		y;
	int		newx;
	int		newy;
	int		coin;
	int		coinc;
	int		maxcoin;
	int		moves;
	t_img	img;
}t_var;

int		check_map(char **map);
void	check_content(t_var *var);
int		check_line(char *map, char c);
int		check_column(char *map, char c, t_var *var);
int		check_count(t_var *var);

void	*free_map(t_var *var);
char	**read_map(t_var *var);
char	**get_map(t_var *var, char **argv);

int		sl_strchr(char *str, char *s);
char	*join(char *s1, char *s2);
void	*error(char *str);
void	free_cmap(char **map);

void	set_var(t_var *var);
void	set_path(t_var *var);
void	print_img(t_var *var, void *img, int i, int j);
void	set_img(t_var *var);
void	img_map(t_var *var);
int		check_image(t_var *var);

void	search_player(t_var *var);
void	max_coin(t_var *var);
int		move_char(int keysym, t_var *var);
void	up(t_var *var);
void	left(t_var *var);
void	down(t_var *var);
void	right(t_var *var);

char	**copy_map(t_var *var);
int		is_inside_map(t_point p, t_var *var);
void	fill_flood(t_point p, char **map, t_var *var);
int		check_cmap(t_var *var);

void	mlx_destroy_protected(void *mlx_ptr, void *img_ptr);
int		exit_game(t_var *var);

#endif