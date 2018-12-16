/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penzo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 12:54:58 by penzo             #+#    #+#             */
/*   Updated: 2018/12/15 20:50:43 by penzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** check if all blocs of the given tetri is placable
** check if the character is '.' && on the table
*/

static int		is_tetri_placeable(int tetr_index, int x, int y, t_table *table)
{
	//ft_putendl("sta is_tetri");
	int			bloc_cnt;

	bloc_cnt = 0;
	while (bloc_cnt < 4)
	{
		if (x + g_tetri_lst[tetr_index].p[bloc_cnt].x >= 0
				&& x + g_tetri_lst[tetr_index].p[bloc_cnt].x < table->len
				&& y + g_tetri_lst[tetr_index].p[bloc_cnt].y >= 0
				&& y + g_tetri_lst[tetr_index].p[bloc_cnt].y < table->len
				&& table->tab[y + g_tetri_lst[tetr_index].p[bloc_cnt].y][x
				+ g_tetri_lst[tetr_index].p[bloc_cnt].x] == '.')
			bloc_cnt++;
		else
		{
			//ft_putendl("end is_tetri");
			return (0);
		}
	}
	//ft_putendl("end is_tetri");
	return (1);
}

static void		delete_tetri(t_table *table, int c, t_pnt *last_pos)
{
	int			x;
	int			y;
	int			is_first;

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
					last_pos->x = x;
					last_pos->y = y;
				}
			}
		}
	}
}

static void		print_tetri(t_table *table, int x, int y, int tetri_index)
{
	printf("table_ad: %p\n", table);
	int			bloc_cnt;

	bloc_cnt = -1;
	while (++bloc_cnt < 4)
		table->tab[y + g_tetri_lst[tetri_index].p[bloc_cnt].y][x + g_tetri_lst[tetri_index].p[bloc_cnt].x]
			= g_tetri_lst[tetri_index].c;
}

t_pnt			*pnt_xplus(t_pnt *pnt)
{
	printf("address2: %p\n", pnt);
	pnt->x += 1;
	return (pnt);
}

t_pnt			*pnt_yplus(t_pnt *pnt)
{
	printf("address3: %p\n", pnt);
	pnt->y += 1;
	pnt->x = 0;
	return (pnt);
}

t_pnt			*pnt_zero(t_pnt *pnt)
{
	printf("address : %p\n", pnt);
	pnt->y = 0;
	pnt->x = 0;
	return (pnt);
}

//add while([x,y] =! '.') [x,y]++;
//void			place_tetri(t_table *table, int x, int y, t_coo *tetri)
//void			place_tetri(t_table *table, int x, int y)
void			place_tetri(t_table *table, t_pnt *coor)
{
	//t_pnt		last_pos;
	static t_pnt	last_pos;
	static int		i = 0;
	static int		rap = 0;//for debug purposes

	if (!(rap % 3))
	{
		//sleep(10);
		//system("vmmap -wide fillit | grep \"Stack\"");
		///system("vmmap fillit | grep \"Stack                             8192K\"");
		///printf("rappel: %d, i: %d, x: %d, y: %d\n",rap , i, coor->x, coor->y);
		//system("gtime --verbose ./fillit");
	}
	rap++;
	if (i >= g_tetri_total)//
	{
		printf("BRAVO !!!!!!!!!!!!!!!!\n\n");
		print_map(table);
		exit(0);
		//return ;//solved: print table
	}
	//ft_putnbr(rap);
	//ft_putendl("eme call");
	if (is_tetri_placeable(i, coor->x, coor->y, table))
	{
		print_tetri(table, coor->x, coor->y, i++);
		//print_map(table);//
		//ft_putendl("");
		place_tetri(table, pnt_zero(coor));
	}
	//
	//if (rap == 87300)
	//	sleep(30);
	//
	printf("address2: %p\n", &coor);
	printf("table_ad: %p\n", &table);
	if (coor->x < table->len - 1)
		place_tetri(table, pnt_xplus(coor));
	if (coor->x == table->len - 1 && coor->y < table->len - 1)
		place_tetri(table, pnt_yplus(coor));
	if (coor->x == table->len - 1 && coor->y == table->len - 1)
	{
		i--;
		if (i < 0)
		{
			i = 0;
			resize_square(table);
			place_tetri(table, pnt_zero(coor));
		}
		delete_tetri(table, g_tetri_lst[i].c, &last_pos);
		if (last_pos.x < table->len - 1)
			place_tetri(table, pnt_xplus(&last_pos));
		if (last_pos.x == table->len - 1 && last_pos.y < table->len - 1)
			place_tetri(table, pnt_yplus(&last_pos));
	}
}
