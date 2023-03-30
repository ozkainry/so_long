/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozozdemi <ozozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:30:47 by ozozdemi          #+#    #+#             */
/*   Updated: 2023/03/30 14:17:10 by ozozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*newline(char *buff, char *temp)
{
	int		i;
	int		j;
	char	*new_buff;

	i = 0;
	j = 0;
	new_buff = malloc(sizeof(char) * (ft_strlen(buff) + size_no_nl(temp, '\n')
				+ 2));
	while (buff[j] != '\0')
	{
		new_buff[j] = buff[j];
		j++;
	}
	while (temp[i] == -1)
		i++;
	while (temp[i] != '\n')
		new_buff[j++] = temp[i++];
	new_buff[j] = '\n';
	j++;
	new_buff[j] = '\0';
	free(buff);
	init_temp(temp);
	return (new_buff);
}

int	only_one(char *temp)
{
	int	i;

	i = 0;
	while (temp[i] != '\0')
	{
		if (temp[i] != -1)
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	temp[BUFFER_SIZE + 1];
	char		*line;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	line = malloc(sizeof(char) * 1);
	line[0] = '\0';
	while (1)
	{
		if (only_one(temp) == 0)
			if (read(fd, temp, BUFFER_SIZE) == 0)
				break ;
		if (gnl_strchr(temp, '\n') == 0)
			line = sjoin(line, temp);
		else if (gnl_strchr(temp, '\n') == 1)
		{
			line = newline(line, temp);
			break ;
		}
	}
	if (line[0] == '\0')
		return (free(line), NULL);
	return (line);
}
