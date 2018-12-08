/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penzo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 17:23:25 by penzo             #+#    #+#             */
/*   Updated: 2018/12/08 15:12:14 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"

typedef struct		s_xy
{
	int				x;
	int				y;
	int				original;
}					t_xy;

typedef struct		s_tetri_coo
{
	struct s_xy		p[4];
}					t_tetri_coo;

int					open_sample(char *filename);
int					format_check(char *filename);
t_tetri_coo			*pieces_check(char *filename, int tetri_cnt);
t_tetri_coo			fill_tetri_coo(char *tetri);
char				**create_square(int nb_tetri);
int					ft_sqrt_up(int n);
char				**resize_square(char **tab, int length);
void				initialise(char ***tab, int length);
void				fill_square(t_tetri_coo *tetri_lst,
					char ***tab, int length, int tetri_total);

#endif
