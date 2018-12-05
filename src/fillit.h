/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penzo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 17:23:25 by penzo             #+#    #+#             */
/*   Updated: 2018/12/05 17:01:03 by amalsago         ###   ########.fr       */
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

int					open_sample(char *av)
unsigned int		format_check(char *av);
unsigned int		pieces_check(char *av, int tetri_cnt);
t_tetri_coo			fill_tetri_coo(char *tetri);

#endif
