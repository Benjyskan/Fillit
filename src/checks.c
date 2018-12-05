/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 20:50:33 by amalsago          #+#    #+#             */
/*   Updated: 2018/12/05 17:32:21 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <unistd.h>

//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>                 // A SUPPRIMMERRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////

/*
** bloc_cnt() allows to count if the number of blocs in tetriminos is equal to 4
** If it equal, function return 1 otherwise 0
*/

unsigned			bloc_cnt(char *buff)
{
	unsigned		i;
	unsigned		bloc_cnt;

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
	return (bloc_cnt == 4);
}

/*
** format_check() allows to validate the input file and it retruns number
** of pieces. It checks the length of the line, if tetri are separated by 1
** newline and if there are only 4 sharp (#) per tetriminos by bloc_cnt()
*/

unsigned			format_check(char *av)
{
	int				fd;
	unsigned		y;
	unsigned		tetri_cnt;
	char			buff[21];

	if (!(fd = open_sample(av)))
		return (0);
	tetri_cnt = 0;
	while ((y = read(fd, buff, 21)) > 0)
	{
		if (y == 20)
		{
			if (!bloc_cnt(buff))
				return (0);
			tetri_cnt++;
			break ;
		}
		if (buff[20] != '\n')
			return (0);
		if (!bloc_cnt(buff))
			return (0);
		tetri_cnt++;
	}
	close(fd);
	return (y == 20 ? tetri_cnt : 0);
}

/*
** Check tetriminos shapes by counting the number of touching sides
*/

unsigned			isvalid_tetri(char *tetri)
{
	unsigned		i;
	unsigned		count;

	i = 0;
	count = 0;
	while (i < 20)
	{
		if (i % 5 == 4)
			i++;
		if (tetri[i] == '#')
		{
			if (i < 19 && tetri[i + 1] == '#')
				count++;
			if (i < 14 && tetri[i + 5] == '#')
				count++;
			if (i > 0 && tetri[i - 1] == '#')
				count++;
			if (i > 4 && tetri[i - 5] == '#')
				count++;
		}
		i++;
	}
	if (count < 6)
		return (0);
	return (1);
}

/*
** pieces_check() verify if pieces are valid and allocate an array to stock
** each piece by calling fill_tetri_coo()
*/

unsigned			pieces_check(char *av, int tetri_cnt)
{
	int				fd;
	unsigned		i;
	char			buff[21];
	t_tetri_coo		*tab;

	if (!(fd = open_sample(av)))
		return (0);
	if (!(tab = (t_tetri_coo *)malloc(sizeof(t_tetri_coo) * tetri_cnt)))
	{
		ft_putendl_fd("error: while malloc tab", 1);
		return (0);
	}
	i = 0;
	while (read(fd, buff, 21) > 0)
	{
		if (!isvalid_tetri(buff))
			return (0);
		tab[i] = fill_tetri_coo(buff);
		i++;
	}
	close(fd);
	return (1);
}
