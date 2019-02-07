/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_shape.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrotsen <mtrotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 14:53:11 by mtrotsen          #+#    #+#             */
/*   Updated: 2019/01/21 14:53:14 by mtrotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			count_square(t_shape *shape)
{
	int	v;
	int i;

	i = 0;
	v = 0;
	while (shape->shape != NULL)
	{
		v++;
		if (shape->next == NULL)
			break ;
		shape = shape->next;
	}
	v = v * 4;
	while (i * i < v)
	{
		i++;
	}
	v = i;
	return (v);
}

int			check_place(char **area, t_shape *shape, int g, int m)
{
	int k;
	int u;
	int i;
	int x;
	int y;

	B(x, shape->x, y, shape->y, i, shape->i, u, k);
	while (k < 4)
	{
		Z(g, m);
		ZQ(g, shape->v);
		if (shape->shape[x][u] == '#' && area[g][m] == '.')
		{
			area[g][m] = shape->letter;
			k++;
		}
		else if (shape->shape[x][u] == '#' && area[g][m] != '.')
			return (0);
		u++;
		m++;
		if (u > 3 || (m > shape->v && u > (shape->v + 1)))
			Q(u, m, x, g, i);
		Z(g, m);
	}
	return (1);
}

char		**ft_place_shape(char **area, t_shape *shape, int v)
{
	int		g;
	int		m;

	shape->v = (v - 1);
	g = shape->g;
	m = shape->m;
	while ((check_place(area, shape, g, m)) != 1)
	{
		if ((g >= (v - 1)) && (m >= (v - 1)) && shape->letter == 'A')
			AR(area);
		if ((g >= (v - 1)) && (m >= (v - 1)))
			EA(area);
		if (area[g][m] != '.' && (m >= (v - 1)))
			P(g, m);
		if (shape->letter == 'A')
		{
			A(area, v);
		}
		else
			area = area_make(shape, area, v);
	}
	shape->g = g;
	shape->m = m;
	return (area);
}

char		**find_shape(char **area, t_shape *shape, int v)
{
	int		f;
	int		c;
	int		i;
	int		x;
	int		y;

	SIGN(f, c, i, x, y);
	while (shape->shape[c][i] != '#')
	{
		CCC(c, i, shape->shape);
	}
	while (shape->shape[x][y] != '#')
	{
		XXX(x, y, shape->shape);
	}
	f++;
	shape->i = i;
	shape->x = x;
	shape->y = y;
	area = ft_place_shape(area, shape, v);
	return (area);
}

void		*ft_put_shape(t_shape *shape, char **area)
{
	t_shape	*tmp;
	t_shape *keep;
	int		v;
	int		m;
	int		g;

	NONS(g, m, shape->g, shape->m, v, shape, keep, area);
	while (shape->shape != NULL)
	{
		area = check_change(area, shape, v);
		while (shape->shape != NULL)
		{
			area = find_shape(area, shape, v);
			M(area, v, shape, keep, shape->next, shape->m, shape->g);
			H(area, shape, m, g, v);
			K(shape->areas, v, shape, area, tmp, shape->next);
			shape = sharr(shape, tmp, area, v);
		}
		GFORCE(shape->next, area);
	}
	print_arr(shape->areas, v);
	shape = keep;
	clean_shape(shape, v);
	ft_clean_arr(area, v);
	return (NULL);
}
