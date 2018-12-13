/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penzo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 12:54:58 by penzo             #+#    #+#             */
/*   Updated: 2018/12/13 17:49:18 by penzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** check if all blocs of the given tetri is placable
** check if the character is '.' && on the table
*/

static int		is_tetri_placeable(t_coo *lst, int x, int y, t_table *table)
{
	int			bloc_cnt;

	bloc_cnt = 0;
	while (bloc_cnt < 4)
	{
		if (x + lst->p[bloc_cnt].x >= 0
				&& x + lst->p[bloc_cnt].x < table->len
				&& y + lst->p[bloc_cnt].y >= 0
				&& y + lst->p[bloc_cnt].y < table->len
				&& table->tab[y + lst->p[bloc_cnt].y][x
				+ lst->p[bloc_cnt].x] == '.')
			bloc_cnt++;
		else
			return (0);
	}
	return (1);
}

/*static int		*delete_tetri(t_table *table, int c)
{
	int			x;
	int			y;
	int			is_first;
	int			*coo;

	coo = malloc(sizeof(int) * 2);
	is_first = 0;
	y = -1;
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
					coo[0] = x;
					coo[1] = y;
				}
			}
		}
	}
	return (coo);
}*/

static t_xy		delete_tetri(t_table *table, int c)
{
	int			x;
	int			y;
	int			is_first;
	t_xy 		coo;

	is_first = 0;
	y = -1;
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
					coo.x = x;
					coo.y = y;
				}
			}
		}
	}
	return (coo);
}

static void		print_tetri(t_table *table, int x, int y, t_coo tetri)
{
	int			bloc_cnt;

	bloc_cnt = -1;
	while (++bloc_cnt < 4)
		table->tab[y + tetri.p[bloc_cnt].y][x + tetri.p[bloc_cnt].x]
			= tetri.c;
}



//add while([x,y] =! '.') [x,y]++;
void			place_tetri(t_table *table, int x, int y, t_coo *tetri)
{
	t_xy		last_pos;
	static int	i = 0;
	static int	rap = 0;

	rap++;
	if (i >= g_tetri_total)//
	{
		//printf("BRAVO !!!!!!!!!!!!!!!!\n");
		return ;//solved: print table
	}
	//if (is_tetri_placeable(tetri, x, y, table))
	if (is_tetri_placeable(&g_tetri_lst[i], x, y, table))
	{
		//printf("print %d tetri on: %d, %d\n", i, x, y);
		print_tetri(table, x, y, g_tetri_lst[i++]);
		printf("%deme rappel\n", rap);
		print_map(table);
		ft_putendl("");
		place_tetri(table, 0, 0, &g_tetri_lst[i]);
	}
	if (x < table->len - 1)
		place_tetri(table, x + 1, y, &g_tetri_lst[i]);
	if (x == table->len - 1 && y < table->len - 1)
		place_tetri(table, 0, y + 1, &g_tetri_lst[i]);
	if (x == table->len - 1 && y == table->len - 1)
	{
		printf("tetri: %d, end of table\n", i+1);
		i--;
		if (i < 0)
		{
			i = 0;
			//resize_square(table->tab, table->len);
			resize_square(table);
			place_tetri(table, 0, 0, &g_tetri_lst[i]);
		}
		last_pos = delete_tetri(table, g_tetri_lst[i].c);
		//printf("last_pos: %d, %d\n", last_pos[0], last_pos[1]);
		//printf("x: %d, y: %d, tab.len: %d\n", x, y, table->len);
		if (last_pos.x < table->len - 1)
			place_tetri(table, last_pos.x + 1, last_pos.y, &g_tetri_lst[i]);
		if (last_pos.x == table->len - 1 && last_pos.y < table->len - 1)
			place_tetri(table, 0, last_pos.y + 1, &g_tetri_lst[i]);
	}
	tetri = NULL;//tejme
}
