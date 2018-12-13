/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penzo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 17:32:08 by penzo             #+#    #+#             */
/*   Updated: 2018/12/13 17:49:25 by penzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int					main(int ac, char **av)
{
	t_table			table;
	int				x;
	int				y;

	if (ac != 2)
	{
		ft_putendl("usage: ./fillit filename");
		return (1);
	}
	if (!check_file(av[1]))
		return (1);
	x = 0;
	y = 0;
	printf("g_tetri_total: %d\n", g_tetri_total);
	table.len = ft_sqrt_up(g_tetri_total * 4);
	printf("table len:%d\n", table.len);
	if (!(table.tab = create_square(table.len)))
		return (1);
	printf("_____________\n");
	place_tetri(&table, x, y, &g_tetri_lst[0]);// added &
	printf("Last main\n");
	print_map(&table);
	return (0);
}
