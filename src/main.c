/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penzo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 17:32:08 by penzo             #+#    #+#             */
/*   Updated: 2018/12/10 18:56:09 by penzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int					main(int ac, char **av)
{
	int				tetri_cnt;
	int				len;
	//t_coo			*lst;//no need since we use a global now
	int				i = 0; ////////////////////////////////////////////////tejme
	char			**tmp;
	t_table			table;

	if (ac != 2)
	{
		ft_putendl_fd("usage: ./fillit filename", 1);
		return (1);
	}
	if (!(tetri_cnt = format_check(av[1])))
	{
		ft_putendl("error");
		return (1);
	}
	if (!(pieces_check(av[1], tetri_cnt)))//set the global
	{
		ft_putendl("error");
		return (1);
	}
	len = ft_sqrt_up(tetri_cnt * 4);
	table.len = &len;
	//*(table.len) = len;
	tmp = create_square(len);
	table.tab = &tmp;
	//*(table.tab) = create_square(len);
	//fill_square(g_tetri_lst, &tab, &len, tetri_cnt);
	place_tetri(table, 0, 0, g_tetri_lst[0]);
	printf("length : %d\n", len);
	while (i < len)
	{
		printf("%s\n", table.tab[0][i]);//pas sure de la syntax
		i++;
	}
	return (0);
}
