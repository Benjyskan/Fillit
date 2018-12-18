/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_tetri.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penzo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 11:29:00 by penzo             #+#    #+#             */
/*   Updated: 2018/12/18 19:12:42 by penzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		print_map(t_table *tab)
{
	int		i;

	i = 0;
	while (i < tab->len)
	{
		ft_putendl(tab->tab[i]);
		i++;
	}
}

void		print_tetri(t_table *table, t_pnt *coor, int index, t_tetri *tetri)
{
	int		bloc_cnt;

	bloc_cnt = -1;
	while (++bloc_cnt < 4)
		table->tab[coor->y + tetri->lst[index].p[bloc_cnt].y]
			[coor->x + tetri->lst[index].p[bloc_cnt].x]
			= tetri->lst[index].c;
}
