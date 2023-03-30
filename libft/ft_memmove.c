/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozozdemi <ozozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:14:03 by ozozdemi          #+#    #+#             */
/*   Updated: 2022/11/25 15:00:58 by ozozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*tabs;
	char	*tabd;

	if (!dest && !src)
		return (NULL);
	tabs = (char *) src;
	tabd = (char *) dest;
	if (dest > src)
	{
		while (n != 0)
		{
			tabd[n - 1] = tabs[n - 1];
			n--;
		}
	}
	else
	{
		tabd = ft_memcpy(dest, src, n);
	}
	return (dest);
}
