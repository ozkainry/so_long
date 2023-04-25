/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozozdemi <ozozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:09:23 by ozozdemi          #+#    #+#             */
/*   Updated: 2023/04/25 13:27:57 by ozozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*join(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = -1;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[++i] != '\0')
		str[j++] = s1[i];
	free (s1);
	i = -1;
	while (s2[++i] != '\0')
		str[j++] = s2[i];
	str[j] = '\0';
	return (str);
}

int	sl_strchr(char *str, char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str[i] == '\0' && s[j] == '\0')
		return (1);
	while (str[i])
	{
		while (str[i + j] == s[j] && str[i + j] && s[j])
			j++;
		if (s[j] == '\0' && str[i + j] == '\0')
			return (1);
		else
			j = 0;
		i++;
	}
	return (0);
}

void	*error(char *str)
{
	write(2, str, ft_strlen(str));
	return (0);
}

void	free_cmap(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
}

void	print_img(t_var *var, void *img, int i, int j)
{
	mlx_put_image_to_window(var->mlx, var->mlx_win, img,
		var->img.width * j, var->img.height * i);
}
