/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penzo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 20:37:49 by penzo             #+#    #+#             */
/*   Updated: 2018/12/03 20:26:20 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <fcntl.h>
#include <unistd.h>

#include "stdio.h" // tejme plz

/*
** First check:
** -line length
** -tetri separate by 1 line
** -only 4 # per tetri
*/

int		format_check(int fd)
{
	char	buff[21];
	int		i;
	int		bloc_cnt;

	while (read(fd, buff, 21))
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

int		pieces_check(int fd)
{
	int		i;
	int		count;
	char	buff[21];

	while (read(fd, buff, 21))
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
		printf("side touching: %d\n", count);//tejme plz
	}
	return (1);
}

//change from main to (initial check/tetri_checker)
int		main(int ac, char **av)
{
	int		fd;

	if (ac != 2)
	{
		ft_putendl("usage: ./fillit [file]");
		return (1);
	}
	fd = open(av[1], O_RDONLY);
	if (!format_check(fd))
	{
		ft_putendl("error");
		return (1);
	}
	close(fd);
	fd = open(av[1], O_RDONLY);
	if (!pieces_check(fd))
	{
		ft_putendl("error");
		return (1);
	}
	return (0);
}
