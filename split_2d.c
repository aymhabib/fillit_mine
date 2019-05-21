/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_2d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymhabib <aymhabib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 21:59:54 by aymhabib          #+#    #+#             */
/*   Updated: 2019/05/21 00:56:21 by aymhabib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_bounds(char *tetriminos, int *minx, int *miny)
{
	int i;
	int x;
	int y;

	i = 0;
	*minx = 3;
	*miny = 3;
	while (tetriminos[i])
	{
		if (tetriminos[i] == '#')
		{
			get_cordinant(&x, &y, i);
			if (x < *minx)
				*minx = x;
			if (y < *miny)
				*miny = y;
		}
		i++;
	}
}

char	**fill_table(void)
{
	char	**tetris;
	int		i;
	int		j;

	i = -1;
	tetris = (char **)malloc(sizeof(tetris) * 5);
	if (!tetris)
		return (NULL);
	while (++i < 4)
		tetris[i] = (char *)malloc(sizeof(*tetris) * 5);
	tetris[4] = NULL;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			tetris[i][j] = '.';
	}
	return (tetris);
}

char	**ft_spliiiit(char *tetriminos, char c)
{
	int		i;
	int		cord[2];
	int		x;
	int		y;
	char	**tetris;

	ft_bounds(tetriminos, &cord[0], &cord[1]);
	tetris = fill_table();
	i = 0;
	while (tetriminos[i])
	{
		if (tetriminos[i] == '#')
		{
			get_cordinant(&x, &y, i);
			tetris[y - cord[1]][x - cord[0]] = c;
		}
		i++;
	}
	return (tetris);
}
