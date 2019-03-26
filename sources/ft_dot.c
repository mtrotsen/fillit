/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrotsen <mtrotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 13:52:24 by mtrotsen          #+#    #+#             */
/*   Updated: 2019/01/03 13:52:28 by mtrotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_dot(char *line)
{
	int		i;
	int		m;

	i = 0;
	m = 0;
	while (line[i])
	{
		m++;
		if (line[i] == '#' || line[i] == '.' || line[i] == '\n')
			i++;
		else
			return (1);
		if (line[i] == '\n' && line[i - 1] == '\n')
			m = 0;
	}
	if (m != 20 && m != 21)
		return (1);
	if (line[i - 1] == '\n' && line[i - 2] == '\n')
		return (1);
	return (0);
}
