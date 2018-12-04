/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 20:50:33 by amalsago          #+#    #+#             */
/*   Updated: 2018/12/04 11:37:25 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <unistd.h>

/*
** First check:
** -line length
** -tetri separate by 1 line
** -only 4 # per tetri
*/

unsigned int		format_check(int fd)
{
	unsigned int	i;
	unsigned int	bloc_cnt;
	char			buff[21];

	while (read(fd, buff, 21) > 0)
	{
		if (buff[20] != '\n')
			return (0);
		i = 0;
		bloc_cnt = 0;
		while (i < 20)
		{
			if (i % 5 == 4)	
			{
				if (buff[i] != '\n')
					return (0);
			}
			else if (buff[i] != '.' && buff[i] != '#')
				return (0);
			if (buff[i] == '#')
				bloc_cnt++;
			i++;
		}
		if (bloc_cnt != 4)
			return (0);
	}
	return (1);
}

/*
** Check tetriminos shapes
** by counting the number of touching sides
*/

unsigned int		pieces_check(int fd)
{
	unsigned int	i;
	unsigned int	count;
	char			buff[21];

	while (read(fd, buff, 21) > 0)
	{
		i = 0;
		count = 0;
		while (i < 20)
		{
			if (i % 5 == 4)
				i++;
			if (buff[i] == '#')
			{
				if (i < 19 && buff[i + 1] == '#')
					count++;
				if (i < 14 && buff[i + 5] == '#')
					count++;
				if (i > 0 && buff[i - 1] == '#')
					count++;
				if (i > 4 && buff[i - 5] == '#')
					count++;
			}
			i++;	
		}
		if (count < 6)
			return (0);
		ft_putstr("side touching: ");
		ft_putnbr(count);
		ft_putchar('\n');
	}
	return (1);
}
