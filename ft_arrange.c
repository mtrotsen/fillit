/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrange.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrotsen <mtrotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 13:28:17 by mtrotsen          #+#    #+#             */
/*   Updated: 2018/12/21 13:28:19 by mtrotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**ft_make_mem(char **shape, int v)
{
	int		i;

	i = 0;
	if (!(shape = malloc(sizeof(char*) * v)))
		return (NULL);
	while (i != v)
	{
		if (!(shape[i] = malloc(sizeof(char) * v)))
			return (NULL);
		i++;
	}
	return (shape);
}

void		ft_clean_arr(char **arrange, int v)
{
	int	c;

	c = 0;
	while (c < v)
	{
		ft_strdel(&arrange[c]);
		c++;
	}
	free(arrange);
	arrange = NULL;
}

t_shape		*ft_make_t_shape(char **arrange, t_shape *shape, char letter)
{
	t_shape *tmp;
	int		c;

	c = 0;
	shape->shape = ft_make_mem(shape->shape, 4);
	while (c < 4)
	{
		shape->shape[c] = ft_strncpy(shape->shape[c], arrange[c], 4);
		c++;
	}
	ALLOCT(tmp);
	tmp->letter = letter;
	tmp->shape = NULL;
	tmp->next = shape;
	shape = tmp;
	return (tmp);
}

char		**ft_look(char *line, char **arrange, int i)
{
	int			j;
	int			c;
	int			v;

	c = 0;
	j = 0;
	v = 0;
	ALLOC(arrange);
	WALLOC(arrange, v);
	while (line[i])
	{
		if (line[i] != '\n')
		{
			arrange[c] = ft_strncpy(arrange[c], &line[i], 4);
			j++;
			i = i + 4;
		}
		W(j, line, i, arrange);
		MY(line, i, c, j);
		i++;
	}
	return (arrange);
}

t_shape		*ft_arrange(char **line)
{
	char	**arrange;
	char	letter;
	t_shape	*shape;
	int		j;
	int		s;

	j = 0;
	letter = 'A';
	if (!(shape = malloc(sizeof(t_shape))))
		return (NULL);
	shape->letter = letter;
	shape->shape = NULL;
	shape->next = NULL;
	s = ft_strlen(line[0]);
	while (j < s)
	{
		arrange = ft_look(*line, arrange, j);
		shape = ft_make_t_shape(arrange, shape, ++letter);
		ft_clean_arr(arrange, 4);
		j = j + 21;
	}
	free(shape);
	shape = shape->next;
	return (shape);
}
