/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozozdemi <ozozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:00:42 by ozozdemi          #+#    #+#             */
/*   Updated: 2022/11/23 12:04:48 by ozozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*tabd;
	char	*tabs;

	if (!dest && !src)
		return (NULL);
	i = 0;
	tabd = (char *) dest;
	tabs = (char *) src;
	while (i < n)
	{
		tabd[i] = tabs[i];
		i++;
	}
	return (dest);
}
