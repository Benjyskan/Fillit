/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 12:55:42 by amalsago          #+#    #+#             */
/*   Updated: 2018/12/08 18:21:27 by amalsago         ###   ########.fr       */
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

char		**create_square(int length)
{
	char	**tab;
	int		i;

	if (!(tab = (char**)malloc(sizeof(char*) * length)))
		return (NULL);
	i = -1;
	while (++i < length)
	{
		if (!(tab[i] = (char*)malloc(sizeof(char) * length)))
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
	initialise(&tab, length);
	return (tab);
}

/*
** Resize square with adding a new row and column
*/

void		resize_square(char ***tab, int *length)
{
	free(*tab);
	*length += 1;
	*tab = create_square(*length);
}

/*
** Initialise a tab with '.'
*/

void		initialise(char ***tab, int length)
{
	int		x;
	int		y;

	y = -1;
	while (++y < length)
	{
		x = -1;
		while (++x < length)
			(*tab)[y][x] = '.';
		(*tab)[y][x] = 0;
	}
}
