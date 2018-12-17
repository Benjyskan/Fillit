/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freellit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 19:48:10 by amalsago          #+#    #+#             */
/*   Updated: 2018/12/17 09:02:02 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		freellit(t_table *table)
{
	int		i;

	i = -1;
	free(g_tetri_lst);
	g_tetri_lst = NULL;
	while (++i < table->len)
	{
		free(table->tab[i]);
		table->tab[i] = NULL;
	}
	free(table->tab);
	table->tab = NULL;
}
