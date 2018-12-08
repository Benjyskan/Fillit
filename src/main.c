/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 20:29:34 by amalsago          #+#    #+#             */
/*   Updated: 2018/12/08 11:03:41 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>//tejme

int				main(int ac, char **av)
{
	unsigned	tetri_cnt;
	unsigned	length;
	t_tetri_coo	*tetri_lst;
	unsigned	i = 0;//tejme
	char		**tab;

	if (ac != 2)
	{
		ft_putendl_fd("usage: ./fillit filename", 1);
		return (1);
	}
	if (!(tetri_cnt = format_check(av[1])))
	{
		ft_putendl_fd("error: bad format", 1);
		return (1);
	}
	if (!(tetri_lst = pieces_check(av[1], tetri_cnt)))
	{
		ft_putendl_fd("error: one or more pieces are invalid", 1);
		return (1);
	}
	/*printf("x=%d y=%d\n", tetri_lst[i].p[0].x, tetri_lst[i].p[0].y);
	printf("x=%d y=%d\n", tetri_lst[i].p[1].x, tetri_lst[i].p[1].y);
	printf("x=%d y=%d\n", tetri_lst[i].p[2].x, tetri_lst[i].p[2].y);
	printf("x=%d y=%d\n\n", tetri_lst[i].p[3].x, tetri_lst[i].p[3].y);*/

	length = ft_sqrt_up(tetri_cnt * 4);
	tab = create_square(length);
	//tab = resize_square(tab, length);
	fill_square(tetri_lst, &tab, length, tetri_cnt);

	while (i < length)
	{
		printf("%s\n", tab[i]);
		i++;
	}
	return (0);
}
