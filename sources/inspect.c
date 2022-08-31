/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inspect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: progerio <progerio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 19:49:53 by progerio          #+#    #+#             */
/*   Updated: 2022/08/29 17:57:58 by progerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_errors(int argc, char *argv[])
{
	char	*ext;

	if (argc != 2)
	{
		if (argc > 2)
			ft_putstr_fd(RED ERROR MANYARG RESET, STDERR);
		else if (argc < 2)
			ft_putstr_fd(RED ERROR MISSMAP RESET, STDERR);
		exit(MLX_ERROR);
	}
	ext = ft_strrchr(argv[1], '.');
	if (ext)
		ext = ft_strnstr(ext, ".ber", 4);
	if (!ext || ext[4] != '\0')
	{
		ft_putstr_fd(RED ERROR BADEXT RESET, STDERR);
		exit(MLX_ERROR);
	}
}
