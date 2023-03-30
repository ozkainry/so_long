/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozozdemi <ozozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:01:41 by ozozdemi          #+#    #+#             */
/*   Updated: 2022/11/11 12:16:41 by ozozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*tabs1;
	unsigned char	*tabs2;

	tabs1 = (unsigned char *) s1;
	tabs2 = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (tabs1[i] != tabs2[i])
			return (tabs1[i] - tabs2[i]);
		i++;
	}
	return (0);
}
