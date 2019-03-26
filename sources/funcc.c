/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrotsen <mtrotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 16:20:58 by mtrotsen          #+#    #+#             */
/*   Updated: 2019/01/14 16:21:00 by mtrotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**ft_chr_str(char **b, char c, int len)
{
	int		i;
	int		f;
	int		t;
	int		v;
	int		g;

	MAKE(v, t, g, f, i, len);
	if (len == 1)
	{
		b[0][0] = c;
		return (b);
	}
	while (g > 0)
	{
		while (f > 0)
		{
			b[i][v] = c;
			v++;
			f--;
		}
		b[i][v] = '\0';
		DEF(f, t, v, i, g);
	}
	return (b);
}

void		print_arr(char **arrange, int j)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = arrange;
	while (i < j)
	{
		ft_putendl(tmp[i]);
		i++;
	}
}

t_shape		*ft_shift_shape(t_shape *convert, t_shape *shape)
{
	t_shape *tmp;
	int		c;
	int		i;

	c = 0;
	i = 0;
	if (!(convert->shape = malloc(sizeof(char*) * 4)))
		return (NULL);
	while (i != 4)
	{
		if (!(convert->shape[i] = malloc(sizeof(char) * 4)))
			return (NULL);
		i++;
	}
	while (c < 4)
	{
		convert->shape[c] = ft_strncpy(convert->shape[c], shape->shape[c], 4);
		c++;
	}
	ALLOCT(tmp);
	tmp->shape = NULL;
	tmp->next = convert;
	convert = tmp;
	return (tmp);
}

t_shape		*ft_shape_shift(t_shape *shape)
{
	t_shape	*convert;

	if (!(convert = malloc(sizeof(t_shape))))
		return (NULL);
	convert->letter = shape->letter;
	convert->shape = NULL;
	convert->next = NULL;
	while (shape->next)
	{
		convert = ft_shift_shape(convert, shape);
		ft_clean_arr(shape->shape, 4);
		free(shape);
		shape = shape->next;
		convert->letter = shape->letter;
	}
	convert = ft_shift_shape(convert, shape);
	convert->letter = shape->letter;
	ft_clean_arr(shape->shape, 4);
	free(shape);
	free(convert);
	convert = convert->next;
	return (convert);
}
