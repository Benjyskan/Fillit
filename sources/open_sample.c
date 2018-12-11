/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_sample.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 14:44:32 by amalsago          #+#    #+#             */
/*   Updated: 2018/12/08 18:57:37 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>

int			open_sample(char *filename)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	return (fd <= 0 ? 0 : fd);
}
