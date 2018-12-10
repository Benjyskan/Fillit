/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penzo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 12:54:58 by penzo             #+#    #+#             */
/*   Updated: 2018/12/10 16:39:17 by penzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
 ** check if all blocs of the given tetri is placable
 ** check if the character is '.' && on the table
 */

//int			is_tetri_placeable(t_coo lst, int *coo, int *len, char ***tab)
int			is_tetri_placeable(t_coo lst, int x, int y, t_table table)
{
	int		bloc_cnt;

	bloc_cnt = 0;
	while (bloc_cnt < 4)
	{
		if (x + lst.p[bloc_cnt].x >= 0
				&& x + lst.p[bloc_cnt].x < *(table.len)
				&& y + lst.p[bloc_cnt].y >= 0
				&& y + lst.p[bloc_cnt].y < *(table.len)
				&& table.tab[0][y + lst.p[bloc_cnt].y][x
				+ lst.p[bloc_cnt].x] == '.')
			bloc_cnt++;
		else
			return (0);
	}
	return (1);
}

int		*delete_tetri(t_table table, int c)
{
	int		x;
	int		y;
	int		is_first;
	//int		coo[2];
	int		*coo;

	coo = malloc(sizeof(int) * 2);
	is_first = 0;
	y = -1;
	while (++y < *(table.len))
	{
		x = -1;
		while (++x < *(table.len))
		{
			if (table.tab[0][y][x] == (char)c)
			{
				table.tab[0][y][x] = '.';
				if (!is_first)
				{
					coo[0] = x;
					coo[1] = y;
				}
			}
		}
	}
	return (coo);
}

/*void		recur(t_coo *lst, int total, char ***tab)
  {
  if (tetri_cnt == total)
//solved
//undo last tetri
//recur(last tetri, x++)
}*/

/*void		fill_square(t_coo *lst, t_table table, int total)
{
	//int		c;
	int		coo[2];
	int		bloc_cnt;
	int		tetri_cnt;

	//c = 'A';
	coo[1] = -1;
	bloc_cnt = -1;
	tetri_cnt = 0;
	while (++coo[1] <= *(table.len))
	{
		coo[0] = -1;
		while (++coo[0] <= *(table.len))
		{
			if (is_tetri_placeable(lst[tetri_cnt], coo, table))
			{
				while (++bloc_cnt < 4)
					table.tab[0][coo[1] + lst[tetri_cnt].p[bloc_cnt].y]
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
		resize_square(table.tab, table.len);
		fill_square(lst, table, total);
	}
	//delete_tetri(tab, (int)'A', *len);
}*/

void	print_tetri(t_table table, int x, int y, t_coo tetri)
{
	int		bloc_cnt;

	bloc_cnt = -1;
	while (++bloc_cnt < 4)
		table.tab[0][y + tetri.p[bloc_cnt].y][x + tetri.p[bloc_cnt].x]
			= tetri.c;
}

//void	place_tetri(t_table table, int *coo, t_coo *lst)
void	place_tetri(t_table table, int x, int y, t_coo *lst)
{
	int			last_pos[2];
	const int	i = 0;
	const int	tetri_total = 2;//tejme

	if (i > tetri_total)
	{
		printf("BRAVO !");
		return ;//solved: print table
	}
	if (is_tetri_placeable(lst[i], x, y, table))
		//print_tetri(table, x, y, lst[i + 1]);
		print_tetri(table, x, y, lst++);
	if (x < *(table.len) - 1)
		place_tetri(table, x + 1, y, lst[i]);
	if (x == *(table.len && y < *(table.len)))
		place_tetri(table, 0, y + 1, lst[i]);
	if (x == length && y == length)
	{
		i--;
		last_pos = delete_tetri(table, lst[i].c);
		if (x < *(table.len) - 1)
			place_tetri(table, last_pos[0] + 1, last_pos[1], lst[i]);
		if (x == *(table.len) && y < *(table.len))
			place_tetri(table, 0, last_pos[1] + 1, lst[i]);
	}
}
