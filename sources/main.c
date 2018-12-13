/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penzo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 17:32:08 by penzo             #+#    #+#             */
/*   Updated: 2018/12/13 11:36:31 by penzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int					main(int ac, char **av)
{
	int				len;
	//int				i = 0;
	char			**tmp;
	t_table			table;

	if (ac != 2)
	{
		ft_putendl("usage: ./fillit filename");
		return (1);
	}
	if (!check_file(av[1]))
		return (1);
	printf("g_tetri_total: %d\n", g_tetri_total);
	len = ft_sqrt_up(g_tetri_total * 4);
	printf("length : %d\n", len);
	table.len = &len;
	printf("table len:%d\n", *(table.len));
	//tmp = create_square(len);
	tmp = create_square(*(table.len));
	table.tab = &tmp;
	printf("_____________\n");
	place_tetri(table, 0, 0, g_tetri_lst[0]);
	printf("length : %d\n", len);
	printf("table len:%d\n", *(table.len));
	/*while (i < len)
	{
		printf("%s\n", table.tab[0][i]);
		i++;
	}*/
	print_map(table);
	return (0);
}
