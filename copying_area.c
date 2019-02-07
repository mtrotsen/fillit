/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copying_area.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrotsen <mtrotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 14:29:13 by mtrotsen          #+#    #+#             */
/*   Updated: 2019/02/01 14:29:18 by mtrotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**ft_mem_create(char **area, int v)
{
	int g;

	g = 0;
	GALLOC(area, v);
	CALLOC(area, v, g);
	return (area);
}

void		clean_shape(t_shape *shape, int v)
{
	while (shape->shape != NULL)
	{
		if (shape->areas != NULL)
			ft_clean_arr(shape->areas, v);
		if (shape->other != NULL && shape->letter != 'A')
			ft_clean_arr(shape->other, v);
		if (shape->next == NULL)
			break ;
		shape = shape->next;
	}
}

char		**area_make(t_shape *shape, char **area, int v)
{
	int b;

	b = 0;
	while (b < v)
	{
		area[b] = ft_strncpy(area[b], shape->other[b], v);
		b++;
	}
	return (area);
}

t_shape		*ft_write_other(t_shape *shape, char **area, int v)
{
	int b;

	b = 0;
	while (b < v)
	{
		shape->other[b] = ft_strncpy(shape->other[b], area[b], v);
		b++;
	}
	return (shape);
}

t_shape		*ft_write_area(t_shape *shape, char **area, int v)
{
	int b;

	b = 0;
	while (b < v)
	{
		shape->areas[b] = ft_strncpy(shape->areas[b], area[b], v);
		b++;
	}
	return (shape);
}
