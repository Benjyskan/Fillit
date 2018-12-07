/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penzo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 12:54:58 by penzo             #+#    #+#             */
/*   Updated: 2018/12/07 18:12:09 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		is_bloc_placeable(t_tetri_coo tetri_lst, unsigned x, unsigned y, unsigned length)
{
	unsigned	bloc_cnt;
	
	bloc_cnt = 0;
	while(bloc_cnt < 4)
	{
		if (x + tetri_lst.p[bloc_cnt].x >= 0
				&& x + tetri_lst.p[bloc_cnt].x < length
				&& y + tetri_lst.p[bloc_cnt].y >= 0
				&& y + tetri_lst.p[bloc_cnt].y < length)
			bloc_cnt++;
		else
			return (0);
	}
	return (1);
}

void	fill_square(t_tetri_coo *tetri_lst, char ***tab, unsigned length)
{
	unsigned	x;	
	unsigned	y;	
	unsigned	i;
	unsigned	bloc_cnt;
	
	bloc_cnt = -1;
	y = -1;
	i = 0;
	while (++y < length)
	{
		x = -1;
		while (++x <= length)
		{
			if (is_bloc_placeable(tetri_lst[i], x, y, length))
			{
				while (++bloc_cnt < 4)
					tab[0][y + tetri_lst[i].p[bloc_cnt].y][x + tetri_lst[i].p[bloc_cnt].x] = '#';
				i++;
			}
		}
	}
	return ;
}
