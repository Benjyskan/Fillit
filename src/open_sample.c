/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_sample.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 14:44:32 by amalsago          #+#    #+#             */
/*   Updated: 2018/12/05 14:54:14 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>

int			open_sample(char *av)
{
	int		fd;

	fd = open(av, O_RDONLY);
	if (fd <= 0)
	{
		ft_putendl_fd("error: opening file", 1);
		return (0);
	}
	return (fd);
}
