/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: progerio <progerio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 19:50:39 by progerio          #+#    #+#             */
/*   Updated: 2022/08/29 17:58:27 by progerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libraries/libft/libft.h"
# include "../libraries/minilibx/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <X11/keysym.h>
# include <X11/X.h>

// Text formatting
# define CYAN "\033[0;36m"
# define RED "\033[0;31m"
# define RESET "\033[0m"
# define CLEAR "\e[1;1H\e[2J"
# define ERROR "Error\n"
# define MISSMAP "Map missing.\n"
# define MANYARG "Too many arguments.\n"
# define BADMAP "Invalid map.\n"
# define BADEXT "Invalid map file extension.\n"

// Error handling
# define MLX_SUCCESS 0
# define MLX_ERROR 1
# define STDERR 2

// Sprites
# define SPRITE_SIZE 32
# define FLOOR_XPM "./sprites/0.xpm"
# define WALL_XPM "./sprites/1.xpm"
# define COLLECT_XPM "./sprites/C.xpm"
# define PLAYER_XPM "./sprites/P.xpm"
# define EXIT_XPM "./sprites/E.xpm"

typedef struct s_data {
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_floor;
	void	*img_wall;
	void	*img_collect;
	void	*img_player;
	void	*img_exit;
	char	**map;
	int		map_height;
	int		map_width;
	int		c_count;
	int		p_count;
	int		e_count;
	int		player_x;
	int		player_y;
	int		collected;
	int		moves;
	int		end_game;
}	t_data;

void	ft_check_errors(int argc, char *argv[]);
int		ft_validate_map(t_data *data);
int		ft_render_map(t_data *data);
int		ft_keypress_handler(int keysym, t_data *data);
int		ft_close_game(t_data *data);
void	ft_move_player(int keysym, t_data *data);
int		ft_end_game(t_data *data);

#endif /* SO_LONG_H */