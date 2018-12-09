/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penzo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 12:54:58 by penzo             #+#    #+#             */
/*   Updated: 2018/12/09 15:27:29 by penzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** check if all blocs of the given tetri is placable
** check if the character is '.' && on the table
*/

int			is_tetri_placeable(t_coo lst, int *coo, int *len, char ***tab)
{
	int		bloc_cnt;

	bloc_cnt = 0;
	while (bloc_cnt < 4)
	{
		if (coo[0] + lst.p[bloc_cnt].x >= 0 && coo[0] + lst.p[bloc_cnt].x < *len
				&& coo[1] + lst.p[bloc_cnt].y >= 0
				&& coo[1] + lst.p[bloc_cnt].y < *len
				&& (*tab)[coo[1] + lst.p[bloc_cnt].y][coo[0]
				+ lst.p[bloc_cnt].x] == '.')
			bloc_cnt++;
		else
			return (0);
	}
	return (1);
}

void		delete_tetri(char ***tab, int c, int len)
{
	int		x;
	int		y;
	y = -1;
	while (++y < len)
	{
		x = -1;
		while (++x < len)
		{
			if ((*tab)[y][x] == (char)c)
				(*tab)[y][x] = '.';
		}
	}
}

/*void		recur(t_coo *lst, int total, char ***tab)
{
	if (tetri_cnt == total)
		//solved
	//undo last tetri
	//recur(last tetri, x++)
}*/

void		fill_square(t_coo *lst, char ***tab, int *len, int total)
{
	//int		c;
	int		coo[2];
	int		bloc_cnt;
	int		tetri_cnt;

	//c = 'A';
	coo[1] = -1;
	bloc_cnt = -1;
	tetri_cnt = 0;
	while (++coo[1] <= *len)
	{
		coo[0] = -1;
		while (++coo[0] <= *len)
		{
			if (is_tetri_placeable(lst[tetri_cnt], coo, len, tab))
			{
				while (++bloc_cnt < 4)
					(*tab)[coo[1] + lst[tetri_cnt].p[bloc_cnt].y]
						[coo[0] + lst[tetri_cnt].p[bloc_cnt].x]
						= lst[tetri_cnt].c;
				bloc_cnt = -1;
				tetri_cnt++;
				coo[0] = -1;
				coo[1] = -1;
				//c++;
			}
		}
	}
	if (tetri_cnt < total)
	{
		//delete_tetri(tab, (int)'A', *len);
		resize_square(tab, len);
		fill_square(lst, tab, len, total);
	}
	//delete_tetri(tab, (int)'A', *len);
}
