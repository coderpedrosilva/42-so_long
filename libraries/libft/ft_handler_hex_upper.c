/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_hex_upper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: progerio <progerio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 19:46:35 by progerio          #+#    #+#             */
/*   Updated: 2022/08/29 17:56:31 by progerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_handler_hex_upper(t_uint num)
{
	size_t	num_size;
	char	*arr;

	arr = ft_itoa_base(num, HEX_BASE_UPPER);
	ft_putstr_fd(arr, 1);
	num_size = ft_strlen(arr);
	free(arr);
	return (num_size);
}
