/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zokon <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 20:45:12 by zokon             #+#    #+#             */
/*   Updated: 2019/01/11 19:18:14 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	tet_check(char *map, int j)
{
	int res;
	int i;

	i = j % 17;
	res = 0;
	if ((i % 4) != 0 && map[j - 1] == '#')
		res++;
	if (i > 3 && map[j - 4] == '#')
		res++;
	if (i < 15 && map[j + 1] == '#' && (i % 4) != 3)
		res++;
	if (i < 12 && map[j + 4] == '#')
		res++;
	return (res);
}

void		fillit_check(char *tetrimino, size_t length)
{
	int		char_line;
	int		char_charp;
	size_t	i;

	i = 0;
	if ((length + 1) % 17 != 0)
		ft_exit(-1);
	while (i < length)
	{
		char_charp = 0;
		char_line = 0;
		while (tetrimino[i] != '\n' && i != length)
		{
			if (tetrimino[i] != '.' && tetrimino[i] != '#')
				ft_exit(-1);
			if (tetrimino[i] == '#')
			{
				char_line++;
				char_charp += tet_check(tetrimino, i);
			}
			i++;
		}
		if (char_line != 4 || ((i++ + 1) % 17) != 0 || char_charp < 5)
			ft_exit(-1);
	}
}

void		ft_matrix_creation(int size)
{
	g_matrix = ft_matrix(size, size, '.');
}

void		ft_print_matrix(void)
{
	int		y;

	y = 0;
	while (y < g_m_size)
	{
		ft_putendl(g_matrix[y]);
		y++;
	}
}

void		ft_exit(int n)
{
	ft_putstr("error\n");
	exit(n);
}
