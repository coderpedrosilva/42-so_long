/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_unsigned.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: progerio <progerio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 19:47:02 by progerio          #+#    #+#             */
/*   Updated: 2022/08/29 17:56:50 by progerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_handler_unsigned(t_uint uint)
{
	size_t	num_size;

	num_size = 1;
	ft_putnbr_fd(((long) uint), 1);
	while (uint >= 10)
	{
		uint /= 10;
		num_size++;
	}
	return (num_size);
}
