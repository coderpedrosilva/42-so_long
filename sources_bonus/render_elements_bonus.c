/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_elements_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: progerio <progerio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 19:52:30 by progerio          #+#    #+#             */
/*   Updated: 2022/08/30 19:24:02 by progerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_render_sprite(t_data *data, void *image, int x, int y)
{
	mlx_put_image_to_window((*data).mlx_ptr, (*data).win_ptr,
		image, x * SPRITE_SIZE, y * SPRITE_SIZE);
}

static void	ft_render_enemy(t_data *data, char *key, int x, int y)
{
	if (*key == 'I' && y % 2 == 0)
		ft_render_sprite(data, (*data).image.enemy_1i, x, y);
	else if (*key == 'I' && y % 2 != 0)
		ft_render_sprite(data, (*data).image.enemy_2i, x, y);
	else if (*key == 'J' && x % 2 == 0)
		ft_render_sprite(data, (*data).image.enemy_1j, x, y);
	else if (*key == 'J' && x % 2 != 0)
		ft_render_sprite(data, (*data).image.enemy_2j, x, y);
	else if (*key == 'K' && y % 2 == 0)
		ft_render_sprite(data, (*data).image.enemy_1k, x, y);
	else if (*key == 'K' && y % 2 != 0)
		ft_render_sprite(data, (*data).image.enemy_2k, x, y);
	else if (*key == 'L' && x % 2 == 0)
		ft_render_sprite(data, (*data).image.enemy_1l, x, y);
	else if (*key == 'L' && x % 2 != 0)
		ft_render_sprite(data, (*data).image.enemy_2l, x, y);
}

static void	ft_render_player(t_data *data, char *key, int x, int y)
{
	if (*key == 'W')
		ft_render_sprite(data, (*data).image.player_w, x, y);
	else if (*key == 'A')
		ft_render_sprite(data, (*data).image.player_a, x, y);
	else if (*key == 'S')
		ft_render_sprite(data, (*data).image.player_s, x, y);
	else if (*key == 'D' || *key == 'P')
		ft_render_sprite(data, (*data).image.player_d, x, y);
}

static void	ft_render_scenario(t_data *data, char *key, int x, int y)
{
	if (*key == 'E' && (*data).collected == (*data).c_count)
		*key = 'O';
	if (*key == 'O')
		ft_render_sprite(data, (*data).image.exit_open, x, y);
	else if (*key == 'E')
		ft_render_sprite(data, (*data).image.exit_close, x, y);
	else if (*key == '1')
		ft_render_sprite(data, (*data).image.wall, x, y);
	else if (*key == '0')
		ft_render_sprite(data, (*data).image.floor, x, y);
	else if (*key == 'C')
		ft_render_sprite(data, (*data).image.collect, x, y);
	else if (*key == 'R')
		ft_render_sprite(data, (*data).image.rip, x, y);
}

void	ft_render_map(t_data *data)
{
	int		i;
	int		j;
	char	*c;

	i = 0;
	while ((*data).map[i])
	{
		j = 0;
		while ((*data).map[i][j])
		{
			c = &(*data).map[i][j];
			if (ft_strchr(SCENARIO_CHARS, *c))
				ft_render_scenario(data, c, j++, i);
			else if (ft_strchr(PLAYER_CHARS, *c))
				ft_render_player(data, c, j++, i);
			else if (ft_strchr(ENEMY_CHARS, *c))
				ft_render_enemy(data, c, j++, i);
		}
		++i;
	}
}
