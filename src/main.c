/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 20:29:34 by amalsago          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/12/10 14:44:11 by penzo            ###   ########.fr       */
=======
/*   Updated: 2018/12/09 17:06:17 by amalsago         ###   ########.fr       */
>>>>>>> 5d32e7b09736c1a323686d13ee570268c88f42d3
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int					main(int ac, char **av)
{
	int				tetri_cnt;
	int				len;
	t_coo			*lst;
	int				i = 0; ////////////////////////////////////////////////tejme
	//char			**tab;
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
	if (!(lst = pieces_check(av[1], tetri_cnt)))
	{
		ft_putendl("error");
		return (1);
	}
	len = ft_sqrt_up(t_cnt * 4);
	*(table.tab) = create_square(len);
	*(table.len) = len;
	//fill_square(lst, &tab, &len, t_cnt);
	place_tetri(table, 0, 0, lst);
	printf("length : %d\n", len);
	while (i < len)
	{
		printf("%s\n", *(table.tab[i]));//pas sure de la syntax
		i++;
	}
	return (0);
}
