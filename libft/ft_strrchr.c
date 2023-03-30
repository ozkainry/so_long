/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozozdemi <ozozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:07:32 by ozozdemi          #+#    #+#             */
/*   Updated: 2023/03/24 16:26:32 by ozozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*tabs;

	i = ft_strlen(s);
	tabs = (char *) s;
	c = (char) c;
	while (i >= 0)
	{
		if (tabs[i] == c)
			return (tabs + i);
		i--;
	}
	return (NULL);
}
