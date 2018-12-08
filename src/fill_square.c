/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penzo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 12:54:58 by penzo             #+#    #+#             */
/*   Updated: 2018/12/08 18:37:04 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** check if all blocs of the given tetri is placable
** check if the character is '.' && on the table
*/

int			is_tetri_placeable(t_tetri_coo lst, int x, int y, int *len, char ***tab)
{
	int		bloc_cnt;

	bloc_cnt = 0;
	while (bloc_cnt < 4)
	{
		if (x + lst.p[bloc_cnt].x >= 0 && x + lst.p[bloc_cnt].x < *len
				&& y + lst.p[bloc_cnt].y >= 0 && y + lst.p[bloc_cnt].y < *len
				&& tab[0][y + lst.p[bloc_cnt].y][x + lst.p[bloc_cnt].x] == '.')
			bloc_cnt++;
		else
			return (0);
	}
	return (1);
}

void		fill_square(t_tetri_coo *lst, char ***tab, int *len, int total)
{
	int		c;
	int		y;
	int		x;
	int		bloc_cnt;
	int		tetri_cnt;

	c = 'A';
	y = -1;
	bloc_cnt = -1;
	tetri_cnt = 0;
	while (++y <= *len)
	{
		x = -1;
		while (++x <= *len)
		{
			if (is_tetri_placeable(lst[tetri_cnt], x, y, len, tab))
			{
				while (++bloc_cnt < 4)
					(*tab)[y + lst[tetri_cnt].p[bloc_cnt].y]
						[x + lst[tetri_cnt].p[bloc_cnt].x] = (char)c;
				bloc_cnt = -1;
				tetri_cnt++;
				x = -1;
				y = -1;
				c++;
			}
		}
	}
	if (tetri_cnt < total)
	{
		resize_square(tab, len);
		fill_square(lst, tab, len, total);
	}
}
