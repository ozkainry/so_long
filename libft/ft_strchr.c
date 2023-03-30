/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozozdemi <ozozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:37:56 by ozozdemi          #+#    #+#             */
/*   Updated: 2022/11/11 14:48:13 by ozozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*tabs;

	i = 0;
	tabs = (char *) s;
	c = (char) c;
	while (tabs[i])
	{
		if (tabs[i] == c)
			return (tabs + i);
		i++;
	}
	if (tabs[i] == c)
		return (tabs + i);
	return (NULL);
}
