/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tetri_coo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 18:49:11 by amalsago          #+#    #+#             */
/*   Updated: 2018/12/05 17:28:05 by amalsago         ###   ########.fr       */
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
			tetri.p[check].original = i;
			tetri.p[check].x = 0;
			tetri.p[check].y = 0;
			check++;
		}
		else if (str[i] == '#')
		{
			tetri.p[check].original = i - tetri.p[0].original;
			tetri.p[check].x = tetri.p[check].original % 5;
			tetri.p[check].y = tetri.p[check].original / 5;
			check++;
		}
		i++;
	}
	return (tetri);
}
