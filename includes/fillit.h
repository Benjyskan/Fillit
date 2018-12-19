/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penzo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 17:23:25 by penzo             #+#    #+#             */
/*   Updated: 2018/12/19 17:17:10 by penzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct		s_table
{
	char			**tab;
	int				len;
}					t_table;

typedef struct		s_xy
{
	int				x;
	int				y;
	int				original;
}					t_xy;

typedef struct		s_pnt
{
	int				x;
	int				y;
}					t_pnt;

typedef struct		s_coo
{
	struct s_xy		p[4];
	int				c;
}					t_coo;

typedef struct		s_tetri_lst
{
	int				total;
	t_coo			*lst;
}					t_tetri;

int					check_file(char *filename, t_tetri *tetri);
int					ft_sqrt_up(int n);
char				**create_square(int nb_tetri);
void				resize_square(t_table *table);
t_coo				fill_tetri_coo(char *tetri);
void				fill_square(t_coo *lst, t_table *table, int total);
void				place_tetri(t_table *table, t_pnt *coor);
void				print_map(t_table *tab);
void				print_tetri(t_table *table, t_pnt *coor, int index,
					t_tetri *tetri);
void				fillit(t_table *table, t_pnt *coor, t_tetri *tetri);
/*
** utils.c
*/
int					freellit(t_table *table, t_tetri *tetri);
void				coor_plus(t_pnt *coor, int len);
void				coor_reset(t_pnt *coor);

#endif
