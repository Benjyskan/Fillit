/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penzo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 12:54:58 by penzo             #+#    #+#             */
/*   Updated: 2018/12/07 20:21:09 by penzo            ###   ########.fr       */
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
		{
			//printf("char: %c\tx: %d, y: %d\n", tab[0][y][x], x, y);
			bloc_cnt++;
		}
		else
			return (0);
	}
	return (1);
}

void	fill_square(t_tetri_coo *tetri_lst, char ***tab, unsigned length)
{
	unsigned	x;
	unsigned	y;
	unsigned	tetri_cnt;
	unsigned	bloc_cnt;
	unsigned	c;
	int			i = 0;//tejme

	c = 65;
	bloc_cnt = -1;
	tetri_cnt = 0;
	y = -1;
	while (++y < length)
	{
		x = -1;
		while (++x <= length)
		{
			if (is_tetri_placeable(tetri_lst[tetri_cnt], x, y, length, tab))
			{
				printf("in tetri_placeable, x: %d, y: %d\n", x, y);
				while (++bloc_cnt < 4)
					tab[0][y + tetri_lst[tetri_cnt].p[bloc_cnt].y]
						[x + tetri_lst[tetri_cnt].p[bloc_cnt].x] = (char)c;
				bloc_cnt = 0;
				tetri_cnt++;
				x = -1;
				y = -1;
				c++;
				while (i < length)
				{
					printf("%s\n", tab[0][i]);
					i++;
				}
				ft_putendl("");
				i = 0;
			}
		}
	}
	return ;
}
