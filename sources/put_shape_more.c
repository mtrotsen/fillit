/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_shape_more.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrotsen <mtrotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 13:33:00 by mtrotsen          #+#    #+#             */
/*   Updated: 2019/02/04 13:33:03 by mtrotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**check_change(char **area, t_shape *shape, int v)
{
	if (area[0][0] == '$')
	{
		ft_clean_arr(area, (v - 1));
		area = ft_mem_create(area, v);
		area = ft_chr_str(area, '.', v);
		return (area);
	}
	if (area[0][0] == '%' && shape->letter == 'A')
	{
		ft_clean_arr(area, v);
		area = ft_mem_create(area, v);
		area = ft_chr_str(area, '.', v);
		return (area);
	}
	else if (area[0][0] == '%' && shape->letter != 'A')
	{
		ft_clean_arr(area, v);
		area = ft_mem_create(area, v);
		area = area_make(shape, area, v);
		return (area);
	}
	return (area);
}

t_shape	*shape_procent(t_shape *shape, int m, int g, int v)
{
	ft_clean_arr(shape->other, v);
	shape = shape->back;
	ft_clean_arr(shape->areas, v);
	m = shape->m;
	g = shape->g;
	if (m > (v - 1))
	{
		g++;
		shape->g = g;
		shape->m = 0;
		return (shape);
	}
	m++;
	shape->m = m;
	return (shape);
}

t_shape	*sharr(t_shape *shape, t_shape *tmp, char **area, int v)
{
	shape = shape->next;
	shape->back = tmp;
	shape->other = ft_mem_create(shape->other, v);
	shape = ft_write_other(shape, area, v);
	shape->g = 0;
	shape->m = 0;
	return (shape);
}
