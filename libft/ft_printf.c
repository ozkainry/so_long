/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozozdemi <ozozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:43:14 by ozozdemi          #+#    #+#             */
/*   Updated: 2023/02/16 18:29:35 by ozozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_len(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

void	ft_putstr_len(char *str, int *len)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		*len = *len + 6;
	}
	else
	{
		while (str[i])
		{
			ft_putchar_len(str[i], len);
			i++;
		}
	}
}

void	ft_printf_check(char c, va_list *args, int *len)
{
	if (c == 'c')
		ft_putchar_len(va_arg(*args, int), len);
	else if (c == '%')
		ft_putchar_len('%', len);
	else if (c == 's')
		ft_putstr_len(va_arg(*args, char *), len);
	else if (c == 'd' || c == 'i')
		ft_putnbr_len(va_arg(*args, int), len);
	else if (c == 'u')
		ft_putnbr_unsigned(va_arg(*args, unsigned int), len);
	else if (c == 'p')
		ft_ptr(va_arg(*args, void *), len);
	else if (c == 'x')
		ft_putnbr_hexa(va_arg(*args, int), "0123456789abcdef", len);
	else if (c == 'X')
		ft_putnbr_hexa(va_arg(*args, int), "0123456789ABCDEF", len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			ft_printf_check(str[i], &args, &len);
			i++;
		}
		else
		{
			ft_putchar_len((char)str[i], &len);
			i++;
		}
	}
	va_end(args);
	return (len);
}
