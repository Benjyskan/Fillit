/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tetri_coo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 18:49:11 by amalsago          #+#    #+#             */
/*   Updated: 2018/12/08 15:08:20 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri_coo			fill_tetri_coo(char *str)
{
	int				i;
	int				bloc_cnt;
	t_tetri_coo		tetri;

	i = 0;
	bloc_cnt = -1;
	while (str[i])
	{
		if (str[i] == '#' && ++bloc_cnt == 0)
		{
			tetri.p[bloc_cnt].original = i;
			tetri.p[bloc_cnt].x = 0;
			tetri.p[bloc_cnt].y = 0;
		}
		else if (str[i] == '#')
		{
			tetri.p[bloc_cnt].original = i - tetri.p[0].original;
			tetri.p[bloc_cnt].x = (i % 5) - (tetri.p[0].original % 5);
			tetri.p[bloc_cnt].y = tetri.p[bloc_cnt].original / 5;
			if (tetri.p[bloc_cnt].x < 0)
				tetri.p[bloc_cnt].y++;
		}
		i++;
	}
	return (tetri);
}
