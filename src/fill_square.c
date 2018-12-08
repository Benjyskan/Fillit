/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penzo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 12:54:58 by penzo             #+#    #+#             */
/*   Updated: 2018/12/08 13:34:00 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
 ** check if all blocs of the given tetri is placable
 ** check if the character is '.' && on the table
 */

int		is_tetri_placeable(t_tetri_coo tetri_lst, unsigned x, unsigned y, unsigned length, char ***tab)
{
	unsigned	bloc_cnt;

	bloc_cnt = 0;
	while(bloc_cnt < 4)
	{
		if (x + tetri_lst.p[bloc_cnt].x >= 0
				&& x + tetri_lst.p[bloc_cnt].x < length
				&& y + tetri_lst.p[bloc_cnt].y >= 0
				&& y + tetri_lst.p[bloc_cnt].y < length
				&& tab[0][y + tetri_lst.p[bloc_cnt].y][x + tetri_lst.p[bloc_cnt].x] == '.')
			bloc_cnt++;
		else
			return (0);
	}
	return (1);
}

void	fill_square(t_tetri_coo *tetri_lst, char ***tab, unsigned length, unsigned tetri_total)
{
	unsigned	x;
	unsigned	y;
	unsigned	tetri_cnt;
	unsigned	bloc_cnt;
	unsigned	c;

	c = 'A';
	y = -1;
	bloc_cnt = -1;
	tetri_cnt = 0;
	while (++y <= length)
	{
		x = -1;
		while (++x <= length)
		{
			if (is_tetri_placeable(tetri_lst[tetri_cnt], x, y, length, tab))
			{
				//printf("in tetri_placeable, x: %d, y: %d\n", x, y);
				while (++bloc_cnt < 4)
					tab[0][y + tetri_lst[tetri_cnt].p[bloc_cnt].y]
						[x + tetri_lst[tetri_cnt].p[bloc_cnt].x] = (char)c;
				bloc_cnt = -1;
				tetri_cnt++;
				x = -1;
				y = -1;
				c++;
			}
		}
	}
	printf("tetri_cnt %d\n", tetri_cnt);
	if (tetri_cnt < tetri_total)
	{
		resize_square(tab, length);
		fill_square(tetri_lst, &tab, length, tetri_total);
	}
}
