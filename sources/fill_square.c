/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penzo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 12:54:58 by penzo             #+#    #+#             */
/*   Updated: 2018/12/18 18:13:58 by penzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** check if all blocs of the given tetri is placable
** check if the character is '.' && on the table
*/

static int		is_tetri_placeable(t_table *table, t_pnt *coor, int index)
{
	int			bloc_cnt;

	bloc_cnt = 0;
	while (bloc_cnt < 4)
	{
		if (coor->x + g_tetri_lst[index].p[bloc_cnt].x >= 0
				&& coor->x + g_tetri_lst[index].p[bloc_cnt].x < table->len
				&& coor->y + g_tetri_lst[index].p[bloc_cnt].y >= 0
				&& coor->y + g_tetri_lst[index].p[bloc_cnt].y < table->len
				&& table->tab[coor->y + g_tetri_lst[index].p[bloc_cnt].y]
				[coor->x + g_tetri_lst[index].p[bloc_cnt].x] == '.')
			bloc_cnt++;
		else
			return (0);
	}
	return (1);
}

static t_pnt	delete_tetri(t_table *table, int c)
{
	int			x;
	int			y;
	int			is_first;
	t_pnt		last_pos;

	y = -1;
	is_first = 0;
	while (++y < table->len)
	{
		x = -1;
		while (++x < table->len)
		{
			if (table->tab[y][x] == (char)c)
			{
				table->tab[y][x] = '.';
				if (!is_first++)
				{
					last_pos.x = x;
					last_pos.y = y;
				}
			}
		}
	}
	return (last_pos);
}

static int		place_letter(t_table *table, t_pnt *coor, int index)
{
	while (table->tab[coor->y][coor->x] != '.')
	{
		if (coor->x >= table->len - 1 && coor->y >= table->len - 1)
			return (0);
		coor_plus(coor, table->len);
	}
	while (!(coor->x >= table->len - 1 && coor->y >= table->len - 1))
	{
		if (is_tetri_placeable(table, coor, index))
		{
			print_tetri(table, coor, index);
			return (1);
		}
		else
			coor_plus(coor, table->len);
	}
	return (0);
}

static int		try_map(t_table *table, t_pnt *coor, int index)
{
	t_pnt		last_pos;

	if (index >= g_tetri_total)
		return (1);
	if (coor->x >= table->len - 1 && coor->y >= table->len - 1)
		return (0);
	if (place_letter(table, coor, index))
	{
		coor_reset(coor);
		if (try_map(table, coor, ++index))
			return (1);
		last_pos = delete_tetri(table, g_tetri_lst[--index].c);
		coor_plus(&last_pos, table->len);
		return (try_map(table, &last_pos, index));
	}
	return (0);
}

void			fillit(t_table *table, t_pnt *coor)
{
	if (try_map(table, coor, 0))
		return ;
	resize_square(table);
	coor_reset(coor);
	fillit(table, coor);
	return ;
}
