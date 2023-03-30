/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozozdemi <ozozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:57:06 by ozozdemi          #+#    #+#             */
/*   Updated: 2022/11/25 16:05:58 by ozozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*dest;
	char	*tab;
	size_t	i;

	dest = NULL;
	i = 0;
	if (nmemb * size == 0 || nmemb <= SIZE_MAX / size)
		dest = (void *) malloc(nmemb * size);
	if (!dest)
		return (NULL);
	tab = (char *) dest;
	while (i < nmemb * size)
	{
	tab[i] = 0;
	i++;
	}
	return (dest);
}
