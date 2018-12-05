/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 20:29:34 by amalsago          #+#    #+#             */
/*   Updated: 2018/12/05 14:28:48 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>

int				main(int ac, char **av)
{
	unsigned	tetri_cnt;

	if (ac != 2)
	{
		ft_putendl_fd("usage: ./fillit filename", 1);
		return (1);
	}
	
	if (!(tetri_cnt = format_check(av[1])))
	{
		ft_putendl_fd("error: bad format", 1);
		return (1);
	}
	if (!(pieces_check(av[1], tetri_cnt)))
	{
		ft_putendl_fd("error: one or more pieces are invalid", 1);
		return (1);
	}
	return (0);
}
