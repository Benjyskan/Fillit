/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penzo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 17:23:25 by penzo             #+#    #+#             */
/*   Updated: 2018/12/09 15:18:10 by penzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

/*
**❗️❗️❗️❗️❗️❗️❗️❗️❗️❗️❗️
** A SUPPRIMER LE stdio.h
**❗️❗️❗️❗️❗️❗️❗️❗️❗️❗️❗️
*/

# include <stdio.h>
# include "../libft/libft.h"

typedef struct		s_xy
{
	int				x;
	int				y;
	int				original;
}					t_xy;

typedef struct		s_coo
{
	struct s_xy		p[4];
	int				c;//gere
}					t_coo;

int					open_sample(char *filename);
int					format_check(char *filename);
t_coo				*pieces_check(char *filename, int tetri_cnt);
t_coo				fill_tetri_coo(char *tetri);
char				**create_square(int nb_tetri);
int					ft_sqrt_up(int n);
void				resize_square(char ***tab, int *len);
void				initialise(char ***tab, int len);
void				fill_square(t_coo *lst,
					char ***tab, int *len, int total);

#endif
