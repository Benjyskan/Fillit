/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 09:16:48 by amalsago          #+#    #+#             */
/*   Updated: 2018/12/19 17:20:52 by penzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_sqrt_up(int n)
{
	int		res;

	res = 0;
	while ((res * res) < n)
		res++;
	return (res);
}

void		coor_plus(t_pnt *coor, int len)
{
	if (coor->x < len - 1)
		coor->x += 1;
	else if (coor->x == len - 1 && coor->y < len - 1)
	{
		coor->x = 0;
		coor->y += 1;
	}
}

void		coor_reset(t_pnt *coor)
{
	coor->x = 0;
	coor->y = 0;
}

int			freellit(t_table *table, t_tetri *tetri)
{
	int		i;

	i = -1;
	if (tetri->lst)
		free(tetri->lst);
	tetri->lst = NULL;
	while (++i < table->len)
	{
		if (table->tab[i])
			free(table->tab[i]);
		table->tab[i] = NULL;
	}
	if (table->tab)
		free(table->tab);
	table->tab = NULL;
	return (1);
}
