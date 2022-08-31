/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_figure_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: progerio <progerio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 19:51:30 by progerio          #+#    #+#             */
/*   Updated: 2022/08/30 19:23:44 by progerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_destroy_images(t_data *data)
{
	mlx_destroy_image((*data).mlx_ptr, (*data).image.floor);
	mlx_destroy_image((*data).mlx_ptr, (*data).image.wall);
	mlx_destroy_image((*data).mlx_ptr, (*data).image.collect);
	mlx_destroy_image((*data).mlx_ptr, (*data).image.exit_close);
	mlx_destroy_image((*data).mlx_ptr, (*data).image.exit_open);
	mlx_destroy_image((*data).mlx_ptr, (*data).image.player_w);
	mlx_destroy_image((*data).mlx_ptr, (*data).image.player_a);
	mlx_destroy_image((*data).mlx_ptr, (*data).image.player_s);
	mlx_destroy_image((*data).mlx_ptr, (*data).image.player_d);
	mlx_destroy_image((*data).mlx_ptr, (*data).image.enemy_1i);
	mlx_destroy_image((*data).mlx_ptr, (*data).image.enemy_1j);
	mlx_destroy_image((*data).mlx_ptr, (*data).image.enemy_1k);
	mlx_destroy_image((*data).mlx_ptr, (*data).image.enemy_1l);
	mlx_destroy_image((*data).mlx_ptr, (*data).image.enemy_2i);
	mlx_destroy_image((*data).mlx_ptr, (*data).image.enemy_2j);
	mlx_destroy_image((*data).mlx_ptr, (*data).image.enemy_2k);
	mlx_destroy_image((*data).mlx_ptr, (*data).image.enemy_2l);
	mlx_destroy_image((*data).mlx_ptr, (*data).image.rip);
	mlx_destroy_image((*data).mlx_ptr, (*data).image.counter);
}
