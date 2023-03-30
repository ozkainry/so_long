/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozozdemi <ozozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:44:22 by ozozdemi          #+#    #+#             */
/*   Updated: 2023/02/16 18:29:42 by ozozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_ptr(void *ptr, int *len)
{
	unsigned long	i;

	if (!ptr)
	{
		write(1, "(nil)", 5);
		*len = *len + 5;
	}
	else
	{
		i = (unsigned long) ptr;
		ft_putchar_len('0', len);
		ft_putchar_len('x', len);
		ft_putnbr_hexa2(i, "0123456789abcdef", len);
	}
}
