/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozozdemi <ozozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:52:39 by ozozdemi          #+#    #+#             */
/*   Updated: 2022/11/14 13:46:31 by ozozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*tabs;

	i = 0;
	tabs = (char *) s;
	while (i < n)
	{
		if (tabs[i] == (char) c)
			return (tabs + i);
		i++;
	}
	return (0);
}
