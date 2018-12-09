/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tetri_coo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 18:49:11 by amalsago          #+#    #+#             */
/*   Updated: 2018/12/09 08:10:33 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_coo			fill_tetri_coo(char *str)
{
	int			i;
	int			b_cnt;
	t_coo		tetri;

	i = 0;
	b_cnt = -1;
	while (str[i])
	{
		if (str[i] == '#' && ++b_cnt == 0)
		{
			tetri.p[b_cnt].original = i;
			tetri.p[b_cnt].x = 0;
			tetri.p[b_cnt].y = 0;
		}
		else if (str[i] == '#')
		{
			tetri.p[b_cnt].original = i - tetri.p[0].original;
			tetri.p[b_cnt].x = (i % 5) - (tetri.p[0].original % 5);
			tetri.p[b_cnt].y = tetri.p[b_cnt].original / 5;
			if (tetri.p[b_cnt].x < 0)
				tetri.p[b_cnt].y++;
		}
		i++;
	}
	return (tetri);
}
