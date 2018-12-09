/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 20:29:34 by amalsago          #+#    #+#             */
/*   Updated: 2018/12/09 08:11:10 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int					main(int ac, char **av)
{
	int				t_cnt;
	int				len;
	t_coo			*lst;
	int				i = 0; ////////////////////////////////////////////////tejme
	char			**tab;

	if (ac != 2)
	{
		ft_putendl_fd("usage: ./fillit filename", 1);
		return (1);
	}
	if (!(t_cnt = format_check(av[1])))
	{
		ft_putendl("error");
		return (1);
	}
	if (!(lst = pieces_check(av[1], t_cnt)))
	{
		ft_putendl("error");
		return (1);
	}
	len = ft_sqrt_up(t_cnt * 4);
	tab = create_square(len);
	fill_square(lst, &tab, &len, t_cnt);
	printf("length : %d\n", len);
	while (i < len)
	{
		printf("%s\n", tab[i]);
		i++;
	}
	return (0);
}
