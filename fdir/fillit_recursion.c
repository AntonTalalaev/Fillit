/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_recursion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 13:44:43 by mwunsch           #+#    #+#             */
/*   Updated: 2019/01/11 19:18:09 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void				ft_matrix_del(char **matrix, int size)
{
	while (size - 1 >= 0)
	{
		free(matrix[size - 1]);
		size--;
	}
	free(matrix);
}

static int			ft_tetrim_add_cheker(int *one_tetrimino, int y, int x)
{
	int		i;
	int		a;

	a = 0;
	i = 0;
	while (i < 4)
	{
		if ((y + one_tetrimino[a + 0]) < 0 ||
				(y + one_tetrimino[a + 0]) >= g_m_size ||
				(x + one_tetrimino[a + 1]) < 0 ||
				(x + one_tetrimino[a + 1]) >= g_m_size)
			break ;
		if (g_matrix[y + one_tetrimino[a + 0]][x + one_tetrimino[a + 1]] != '.')
			break ;
		i++;
		a += 2;
	}
	if (i == 4)
		return (0);
	return (-1);
}

static void			ft_print_tetrim(int *one_tetrimino, int y, int x, char c)
{
	int		i;
	int		a;

	i = 0;
	a = 0;
	while (i < 4)
	{
		g_matrix[y + one_tetrimino[a + 0]][x + one_tetrimino[a + 1]] = c;
		i++;
		a += 2;
	}
}

static int			ft_one_tetrim_adder(int tetrim, int y, int x, char c)
{
	if (tetrim == g_t_num)
		return (0);
	if (ft_tetrim_add_cheker(g_tetrimino[tetrim], y, x) == -1)
	{
		if ((x == g_m_size - 1) && !(x = 0))
			y++;
		else
			x++;
		if (y == g_m_size)
			return (-1);
		return (ft_one_tetrim_adder(tetrim, y, x, c));
	}
	ft_print_tetrim(g_tetrimino[tetrim], y, x, c);
	if (ft_one_tetrim_adder(tetrim + 1, 0, 0, c + 1) == 0)
		return (0);
	ft_print_tetrim(g_tetrimino[tetrim], y, x, '.');
	if ((x == g_m_size - 1) && !(x = 0))
		y++;
	else
		x++;
	if (y == g_m_size)
		return (-1);
	return (ft_one_tetrim_adder(tetrim, y, x, c));
}

int					fillit_recursion(int size)
{
	ft_matrix_creation(size);
	if (ft_one_tetrim_adder(0, 0, 0, 'A') == -1)
	{
		ft_matrix_del(g_matrix, g_m_size);
		return (fillit_recursion(++g_m_size));
	}
	return (0);
}
