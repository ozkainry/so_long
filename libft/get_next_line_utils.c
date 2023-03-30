/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozozdemi <ozozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:12:21 by ozozdemi          #+#    #+#             */
/*   Updated: 2023/03/30 14:18:20 by ozozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	gnl_strchr(char *temp, char c)
{
	int	i;

	i = 0;
	while (temp[i] != '\0')
	{
		if (temp[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	gnl_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	size_no_nl(char *temp, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (temp[i] == -1)
		i++;
	while (temp[i] != c)
	{
		i++;
		j++;
	}
	return (j);
}

void	init_temp(char *temp)
{
	int	i;

	i = 0;
	while (temp[i] != '\n' && temp[i] != '\0')
	{
		temp[i] = -1;
		i++;
	}
	if (temp[i] == '\n')
		temp[i] = -1;
}

char	*sjoin(char *buff, char *temp)
{
	int		i;
	int		j;
	char	*new_buff;

	i = 0;
	j = 0;
	new_buff = malloc(sizeof(char) * (ft_strlen(buff) + size_no_nl(temp, '\0')
				+ 1));
	while (buff[j] != '\0')
	{
		new_buff[j] = buff[j];
		j++;
	}
	while (temp[i] == -1)
		i++;
	while (temp[i] != '\0' && temp[i] != -1)
	{
		new_buff[j] = temp[i];
		i++;
		j++;
	}
	new_buff[j] = '\0';
	free(buff);
	init_temp(temp);
	return (new_buff);
}
