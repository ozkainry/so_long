/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozozdemi <ozozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 03:57:39 by ozozdemi          #+#    #+#             */
/*   Updated: 2023/03/31 03:58:12 by ozozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_destroy_protected(void *mlx_ptr, void *img_ptr)
{
	if (img_ptr)
	{
		mlx_destroy_image(mlx_ptr, img_ptr);
	}
}
