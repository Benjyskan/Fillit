/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penzo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 12:54:58 by penzo             #+#    #+#             */
/*   Updated: 2018/12/07 17:21:54 by penzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fill_square(t_tetri_coo *tetri_lst, char ***tab, unsigned length)
{
	unsigned	x;	
	unsigned	y;	
	unsigned	bloc_cnt = 0;

	y = -1;
	while (++y < length)
	{
		x = -1;
		while (++x <= length)
		{
			while(bloc_cnt < 4)
			{
				if (x + tetri_lst[0].p[bloc_cnt].x >= 0
						&& x + tetri_lst[0].p[bloc_cnt].x < length
						&& y + tetri_lst[0].p[bloc_cnt].y >= 0
						&& y + tetri_lst[0].p[bloc_cnt].y < length)
				{
					tab[0][y + tetri_lst[0].p[bloc_cnt].y][x + tetri_lst[0].p[bloc_cnt].x]
						= '#';
					bloc_cnt++;
				}
				else
					break;
			}
		}
	}
	return ;
}
