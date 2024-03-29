/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: progerio <progerio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 19:50:17 by progerio          #+#    #+#             */
/*   Updated: 2022/08/29 17:58:10 by progerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_move_player_up(t_data *data)
{
	if ((*data).map[(*data).player_y - 1][(*data).player_x] == '1')
		return (FALSE);
	else if ((*data).map[(*data).player_y - 1][(*data).player_x] == 'C')
		(*data).collected++;
	else if ((*data).map[(*data).player_y - 1][(*data).player_x] == 'E')
		return (ft_end_game(data));
	(*data).map[(*data).player_y][(*data).player_x] = '0';
	(*data).map[--((*data).player_y)][(*data).player_x] = 'P';
	return (TRUE);
}

static int	ft_move_player_left(t_data *data)
{
	if ((*data).map[(*data).player_y][(*data).player_x - 1] == '1')
		return (FALSE);
	else if ((*data).map[(*data).player_y][(*data).player_x - 1] == 'C')
		(*data).collected++;
	else if ((*data).map[(*data).player_y][(*data).player_x - 1] == 'E')
		return (ft_end_game(data));
	(*data).map[(*data).player_y][(*data).player_x] = '0';
	(*data).map[(*data).player_y][--((*data).player_x)] = 'P';
	return (TRUE);
}

static int	ft_move_player_down(t_data *data)
{
	if ((*data).map[(*data).player_y + 1][(*data).player_x] == '1')
		return (FALSE);
	else if ((*data).map[(*data).player_y + 1][(*data).player_x] == 'C')
		(*data).collected++;
	else if ((*data).map[(*data).player_y + 1][(*data).player_x] == 'E')
		return (ft_end_game(data));
	(*data).map[(*data).player_y][(*data).player_x] = '0';
	(*data).map[++((*data).player_y)][(*data).player_x] = 'P';
	return (TRUE);
}

static int	ft_move_player_right(t_data *data)
{
	if ((*data).map[(*data).player_y][(*data).player_x + 1] == '1')
		return (FALSE);
	else if (data->map[(*data).player_y][(*data).player_x + 1] == 'C')
		(*data).collected++;
	else if ((*data).map[data->player_y][(*data).player_x + 1] == 'E')
		return (ft_end_game(data));
	(*data).map[(*data).player_y][(*data).player_x] = '0';
	(*data).map[(*data).player_y][++((*data).player_x)] = 'P';
	return (TRUE);
}

void	ft_move_player(int keysym, t_data *data)
{
	int	player_moved;

	player_moved = 0;
	if (keysym == XK_Up || keysym == XK_w)
		player_moved = ft_move_player_up(data);
	else if (keysym == XK_Left || keysym == XK_a)
		player_moved = ft_move_player_left(data);
	else if (keysym == XK_Down || keysym == XK_s)
		player_moved = ft_move_player_down(data);
	else if (keysym == XK_Right || keysym == XK_d)
		player_moved = ft_move_player_right(data);
	if (player_moved)
		ft_printf(CYAN CLEAR"Moves: %d\n"RESET, ++((*data).moves));
}
