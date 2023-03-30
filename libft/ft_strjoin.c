/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozozdemi <ozozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:11:50 by ozozdemi          #+#    #+#             */
/*   Updated: 2023/03/02 14:37:15 by ozozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*def;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	def = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (def == NULL)
		return (NULL);
	while (s1[i])
	{
		def[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		def[i] = s2[j];
		i++;
		j++;
	}
	def[i] = '\0';
	return (def);
}
