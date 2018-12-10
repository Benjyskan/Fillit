/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 20:50:33 by amalsago          #+#    #+#             */
/*   Updated: 2018/12/10 21:49:26 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <unistd.h>

/*
** bloc_cnt() allows to count if the number of blocs in tetriminos is equal to 4
** If it equal, function return 1 otherwise 0
*/

int					bloc_cnt(char *buff)
{
	int				i;
	int				bloc_cnt;

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

int					format_check(char *filename)
{
	int				y;
	int				fd;
	char			buff[21];

	if (!(fd = open_sample(filename)))
		return (0);
	while ((y = read(fd, buff, 21)) > 0)
	{
		if (y == 20)
		{
			if (!bloc_cnt(buff))
				return (0);
			g_tetri_total++;
			break ;
		}
		if (buff[20] != '\n')
			return (0);
		if (!bloc_cnt(buff))
			return (0);
		g_tetri_total++;
	}
	close(fd);
	return (pieces_check(filename) == 1 ? 1 : 0);
}

/*
** Check tetriminos shapes by counting the number of touching sides
*/

int					isvalid_tetri(char *tetri)
{
	int				i;
	int				count;

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
	return (count < 6 ? 0 : 1);
}

/*
** pieces_check() verify if pieces are valid and allocate an array to stock
** each pieces by calling fill_tetri_coo()
*/

int					pieces_check(char *filename)
{
	int				fd;
	int				i;
	char			buff[21];
	//t_coo			*tetri_lst;//no need since it is a global now
	
	if (!(fd = open_sample(filename)))
		return (0);
	if (!(g_tetri_lst = (t_coo *)malloc(sizeof(t_coo) * g_tetri_total)))
	{
		ft_putendl("error");
		return (0);
	}
	i = 0;
	while (read(fd, buff, 21) > 0)
	{
		if (!isvalid_tetri(buff))
			return (0);
		g_tetri_lst[i] = fill_tetri_coo(buff);
		g_tetri_lst[i].c = i + 65;
		//printf("%c\n", (char)g_tetri_lst[i].c);
		i++;
	}
	close(fd);
	return (1);
}
