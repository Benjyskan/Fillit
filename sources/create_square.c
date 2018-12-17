/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 12:55:42 by amalsago          #+#    #+#             */
/*   Updated: 2018/12/17 11:14:59 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "fillit.h"

/*
** Initialise a tab with '.'
*/

static void		initialise(char ***tab, int len)
{
	int			x;
	int			y;

	y = -1;
	while (++y < len)
	{
		x = -1;
		while (++x < len)
			(*tab)[y][x] = '.';
		(*tab)[y][x] = 0;
	}
}

/*
** Create a square depending of length and initialising int with '.'
*/

char			**create_square(int len)
{
	int			i;
	char		**tab;

	if (!(tab = (char**)malloc(sizeof(char*) * len)))
		return (NULL);
	i = -1;
	while (++i < len)
	{
		if (!(tab[i] = (char*)malloc(sizeof(char) * len + 1)))
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

void			resize_square(t_table *table)
{
	int			i;

	i = -1;
	while (++i < table->len)
		free(table->tab[i]);
	free(table->tab);
	table->len += 1;
	table->tab = create_square(table->len);
}
