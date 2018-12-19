/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penzo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 17:32:08 by penzo             #+#    #+#             */
/*   Updated: 2018/12/19 12:05:58 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				main(int ac, char **av)
{
	t_table		table;
	t_tetri		tetri;
	t_pnt		coor;

	if (ac != 2)
	{
		ft_putendl("usage: ./fillit filename");
		return (1);
	}
	if (check_file(av[1], &tetri) <= 0)
		return (1);
	coor_reset(&coor);
	table.len = ft_sqrt_up(tetri.total * 4);
	if (!(table.tab = create_square(table.len)))
		return (1);
	fillit(&table, &coor, &tetri);
	print_map(&table);
	freellit(&table, &tetri);
	return (0);
}
