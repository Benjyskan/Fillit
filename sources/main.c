/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penzo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 17:43:20 by penzo             #+#    #+#             */
/*   Updated: 2018/12/19 17:43:26 by penzo            ###   ########.fr       */
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
		exit (1);
	}
	if (check_file(av[1], &tetri) <= 0)
		exit(freellit(&table, &tetri));
	coor_reset(&coor);
	table.len = ft_sqrt_up(tetri.total * 4);
	if (!(table.tab = create_square(table.len)))
		exit(freellit(&table, &tetri));
	fillit(&table, &coor, &tetri);
	print_map(&table);
	freellit(&table, &tetri);
	return (0);
}
