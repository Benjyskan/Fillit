/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tetri_coo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 18:49:11 by amalsago          #+#    #+#             */
/*   Updated: 2018/12/05 16:48:24 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri_coo		fill_tetri_coo(char *str)
{
	unsigned		i;
	unsigned		check;
	t_tetri_coo		tetri;

	i = 0;
	check = 0;
	while (str[i])
	{
		if (check == 0 && str[i] == '#')
		{
			tetri.p0.original = i;
			tetri.p0.x = 0;
			tetri.p0.y = 0;
			check++;
		}
		else if (check == 1 && str[i] == '#')
		{
			tetri.p1.original = i - tetri.p0.original;
			tetri.p1.x = tetri.p1.original % 5;
			tetri.p1.y = tetri.p1.original / 5;
			check++;
		}
		else if (check == 2 && str[i] == '#')
		{
			tetri.p2.original = i - tetri.p0.original;
			tetri.p2.x = tetri.p2.original % 5;
			tetri.p2.y = tetri.p2.original / 5;
			check++;
		}
		else if (check == 3 && str[i] == '#')
		{
			tetri.p3.original = i - tetri.p0.original;
			tetri.p3.x = tetri.p3.original % 5;
			tetri.p3.y = tetri.p3.original / 5;
		}
		i++;
	}
	return (tetri);
}
