/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penzo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 17:32:08 by penzo             #+#    #+#             */
/*   Updated: 2018/12/10 22:26:59 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int					main(int ac, char **av)
{
	int				len;
	int				i = 0; ////////////////////////////////////////////////tejme
	char			**tmp;
	t_table			table;

	if (ac != 2)
	{
		ft_putendl_fd("usage: ./fillit filename", 1);
		return (1);
	}
	if (!check_file(av[1]))
		return (1);
printf("%d\n", g_tetri_total);
	len = ft_sqrt_up(g_tetri_total * 4);
	table.len = &len;
	tmp = create_square(len);
	table.tab = &tmp;
	place_tetri(table, 0, 0, g_tetri_lst[0]);
printf("length : %d\n", len);
	while (i < len)
	{
		printf("%s\n", table.tab[0][i]);//pas sure de la syntax
		i++;
	}
	return (0);
}
