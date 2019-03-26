/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrotsen <mtrotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:39:31 by mtrotsen          #+#    #+#             */
/*   Updated: 2018/12/11 15:39:33 by mtrotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	char	**area;
	t_shape	*shape;

	area = NULL;
	if (argc != 2)
	{
		ft_putendl("Usage: ./fillit sample_file");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (!(ft_read_file(fd, &line)))
	{
		close(fd);
		return (0);
	}
	shape = ft_arrange(&line);
	shape = ft_shape_shift(shape);
	ft_put_shape(shape, area);
	close(fd);
	return (0);
}
