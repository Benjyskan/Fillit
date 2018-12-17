/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penzo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 17:32:08 by penzo             #+#    #+#             */
/*   Updated: 2018/12/17 15:00:52 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int					main(int ac, char **av)
{
	t_table			table;
	t_pnt			coor;

	if (ac != 2)
	{
		ft_putendl("usage: ./fillit filename");
		return (1);
	}
	if (check_file(av[1]) <= 0)
		return (1);
	coor_reset(&coor);
	table.len = ft_sqrt_up(g_tetri_total * 4);
	if (!(table.tab = create_square(table.len)))
		return (1);
	fillit(&table, &coor);
	print_map(&table);
	freellit(&table);
	return (0);
}
