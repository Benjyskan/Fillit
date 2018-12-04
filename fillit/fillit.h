/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penzo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 17:23:25 by penzo             #+#    #+#             */
/*   Updated: 2018/12/04 18:04:23 by penzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"

unsigned int	format_check(int fd);
unsigned int	pieces_check(int fd);
typedef struct	s_xy
{
	int			x;
	int			y;
}				t_xy;
typedef struct	s_tetri_coo
{
	struct s_xy		p0;
	struct s_xy		p1;
	struct s_xy		p2;
	struct s_xy		p3;
}				t_tetri_coo;
#endif
