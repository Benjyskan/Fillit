/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 12:55:42 by amalsago          #+#    #+#             */
/*   Updated: 2018/12/08 18:30:22 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "fillit.h"

int			ft_sqrt_up(int n)
{
	int		res;

	res = 0;
	while (res * res < n)
		res++;
	return (res);
}

/*
** Create a square depending of length and initialising int with '.'
*/

char		**create_square(int len)
{
	char	**tab;
	int		i;

	if (!(tab = (char**)malloc(sizeof(char*) * len)))
		return (NULL);
	i = -1;
	while (++i < len)
	{
		if (!(tab[i] = (char*)malloc(sizeof(char) * len)))
		{
			while (i-- > 0)
			{
				free(tab[i]);
				tab[i] = NULL;
			}
			free(tab);
			tab = NULL;
			return (NULL);
		}
	}
	initialise(&tab, len);
	return (tab);
}

/*
** Resize square with adding a new row and column
*/

void		resize_square(char ***tab, int *len)
{
	free(*tab);
	*len += 1;
	*tab = create_square(*len);
}

/*
** Initialise a tab with '.'
*/

void		initialise(char ***tab, int len)
{
	int		x;
	int		y;

	y = -1;
	while (++y < len)
	{
		x = -1;
		while (++x < len)
			(*tab)[y][x] = '.';
		(*tab)[y][x] = 0;
	}
}
