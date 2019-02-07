/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrotsen <mtrotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 13:46:48 by mtrotsen          #+#    #+#             */
/*   Updated: 2018/12/13 13:46:51 by mtrotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				other_cases(char **line)
{
	static int	i = 0;

	if (i == 0 && (ft_strncmp(*line, "\n", 1)) == -10)
		return (1);
	i++;
	return (0);
}

int				check_valid(char **line, char *cpy)
{
	int		i;
	int		o;

	o = 0;
	i = 0;
	while (line[0][o])
	{
		if (line[0][o] == '#')
		{
			i++;
			if (line[0][o + 1] == '#')
				i++;
			if (line[0][o - 1] == '#')
				i++;
			if (cpy && (line[0][o] == '#') && (cpy[o] == '#'))
				i = i + 2;
		}
		o++;
	}
	return (i);
}

static int		valid_shape(char **line)
{
	static char	*cpy;
	static int	i = 0;
	static int	j = 0;
	static int	f = 0;

	f++;
	if (f > 130)
		return (1);
	IF(**line, i, j, cpy);
	i = i + check_valid(line, cpy);
	ft_strdel(&cpy);
	cpy = ft_strdup(line[0]);
	j++;
	if (j == 4)
	{
		j = -1;
		if (i != 10 && i != 12)
		{
			i = 0;
			return (1);
		}
		else
			return (0);
	}
	return (0);
}

static int		valid_file(char **line)
{
	static int		c = 0;
	static int		j = 0;
	static int		m = 0;

	m++;
	if (c == 0 && (ft_strncmp(*line, "\n", 1)) == -10)
	{
		if (m != 5)
			return (1);
		L(c, j, m);
		return (0);
	}
	else if (c == 1 && (ft_strncmp(*line, "\n", 1)) == -10)
	{
		F(c, j, m);
	}
	else if ((ft_strlen(*line)) != 4)
	{
		j++;
		CHECKLINE(j, c);
		return (1);
	}
	CHECKLINE(j, c);
	j++;
	return (0);
}

char			*ft_read_file(int fd, char **line)
{
	char	*move;
	char	*lol;

	move = ft_strnew(0);
	while (get_next_line(fd, line) == 1)
	{
		if ((valid_file(line)) == 1)
			FREE(*line);
		if ((valid_shape(line)) == 1)
			FREE(*line);
		if ((other_cases(line)) == 1)
			FREE(*line);
		MOVE(lol, move, *line, &lol);
		MOVE(lol, move, "\n", &lol);
		free(*line);
	}
	*line = move;
	if ((ft_dot(*line)) == 1)
		FREE(*line);
	return (*line);
}
