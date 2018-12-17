/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 09:16:48 by amalsago          #+#    #+#             */
/*   Updated: 2018/12/17 09:32:15 by amalsago         ###   ########.fr       */
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
