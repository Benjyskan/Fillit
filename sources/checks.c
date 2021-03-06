/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 20:50:33 by amalsago          #+#    #+#             */
/*   Updated: 2018/12/19 17:45:26 by penzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "fillit.h"

/*
** Check tetriminos shapes by counting the number of touching sides
*/

static int			isvalid_tetri(char *tetri)
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

static int			pieces_check(char *filename, t_tetri *tetri)
{
	int				i;
	int				fd;
	char			buff[21];

	if ((fd = open(filename, O_RDONLY)) == -1)
		return (fd);
	if (!(tetri->lst = (t_coo *)malloc(sizeof(t_coo) * tetri->total)))
	{
		ft_putendl("error");
		return (0);
	}
	i = 0;
	while (read(fd, buff, 21) > 0)
	{
		buff[20] = 0;
		if (!isvalid_tetri(buff))
			return (0);
		tetri->lst[i] = fill_tetri_coo(buff);
		tetri->lst[i].c = i + 'A';
		i++;
	}
	return ((close(fd) == -1) ? -1 : 1);
}

/*
** bloc_cnt() allows to count if the number of blocs in tetriminos is equal to 4
** If it equal, function return 1 otherwise 0
*/

static int			bloc_cnt(char *buff)
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

static int			format_check(char *filename, t_tetri *tetri)
{
	int				y;
	int				fd;
	char			buff[21];

	if ((fd = open(filename, O_RDONLY)) == -1 || read(fd, buff, 0) == -1)
		return (-1);
	while ((y = read(fd, buff, 21)) > 0)
	{
		if (y == 20)
		{
			if (!bloc_cnt(buff))
				return (0);
			tetri->total++;
			break ;
		}
		if (y < 20 || buff[20] != '\n' || !bloc_cnt(buff))
			return (0);
		tetri->total++;
	}
	if ((y == 0 && tetri->total) || tetri->total > 26 || tetri->total == 0)
		return (0);
	if (close(fd) == -1)
		return (-1);
	return (1);
}

/*
** check_file() function takes filename in parametre and pass it to
** format_check() and pieces_check() and prints error message if one
** of calling functions returns 0
*/

int					check_file(char *filename, t_tetri *tetri)
{
	if (format_check(filename, tetri) <= 0
			|| pieces_check(filename, tetri) <= 0)
	{
		ft_putendl("error");
		return (0);
	}
	return (1);
}
